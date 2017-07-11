# 1 Canvas

Canvas是用来控制一组UI元素渲染方式的组件。所有UI元素必须是Canvas的孩子。每个Canvas都有几种不同的渲染模式（render modes）。一个场景中可以有多个Canvas。

- Screen Space - Overlay(default)
	- UI覆盖整个屏幕，根据屏幕大小变化自动调整大小
	- 所有UI元素都绘制在场景中其他元素的前面
	- 不可手动编辑Rect Transform组件
	- 有pixel perfect选项用于在渲染时自动调整到最接近的像素，可用于锐化外观
- Screen Space - Camera
	- 被场景中某个指定的camera来渲染
	- canvas自动填充摄像头的视野，当摄像机的viewport设置修改时也会自动调整大小
	- 不可手动编辑Rect Transform组件
	- 有pixel perfect
	- render camera用来设置渲染此canvas上UI元素的摄像机。不写就是Screen Space-Overlay
	- plane distance可以设置UI的位置，必须在摄像头的clipping planes设置中的near和far范围内
- World Space
	- UI元素可以在场景内部被渲染
	- 做角色名签、对话框等东西
	- Event Camera用于确定由哪个摄像机来检测事件，例如UI点击事件（事件跟摄像机有什么关系？）一般会指定为渲染整个场景的摄像机。
	- Receives Events指示是否Canvas上的UI元素会接收到点击或者悬浮等事件
	- Sorting Layer和Order in Layer用于控制渲染顺序
	- 元素按照自顶向下的顺序渲染
	
## 2 Rect Transform组件

用来在UI元素上代替常见的transform组件。区别在于：

- 锚点（pivot point）的设置，可以锚定到父亲元素。这货大概跟ps里围绕着旋转的那个锚点是一个东西。不可超出父节点的边界范围。
	- 把锚点放在UI元素的各个角上：父元素拉伸时，会保持UI元素在父节点的百分比位置，跟随拉伸。
	- 把锚点放在父节点的边界上：UI元素与父节点的边界间的距离会保持固定。
	- 把两个锚点放在一起，这个方向上就不会发生拉伸。
- 当UI元素在local空间编辑时，矩形和操作点与UI元素对齐
- 当UI元素在global空间编辑时，矩形和操作点全局对齐
- pivot定义了UI元素的轴心，(1, 1)表示右上角，(0, 0)表示左下角
- 调整大小（width和height）的时候不会影响字体的大小，但缩放（scale）会

## 3 Button

Button元素可以检测用户输入并触发一个事件。

- 需要一个Image脚本和一个Button脚本
- Interactable可以控制按钮是否接受输入，为false时，按钮不能点。
- 一个按钮有normal, highlighted, pressed, disable四种状态，可以通过Transition来控制。
	- None: 表示四种状态下按钮的形态无变化，无视觉反馈，一直表现为normal
	- ColorTint: 每个状态使用同一个图像元素。其中Target Graphic设置为button元素上的image组件。Color Multiplier会把每个状态的调色乘以这个值。用于设置在增亮图像上基色小于白色的颜色，或者设置小于全透明的alpha通道。Fade Duration指两个状态间的过渡时间（秒）
	- SpriteSwap: 在不同状态使用不同的sprite。
	- Animation: 允许每个转变通过Unity的动画系统进行完全动画化
- Navigation描述使用键盘或控制时，选择UI元素的处理方式，Automatic就好
- 事件：
	- 创建canvas时，会添加一个EventSystem用于捕捉事件，可以处理按钮的点击，OnClick函数需要写在一个类里在OnClick选框被设置，可以有一个参数。

## 4 image组件

image组件用来给UI元素在屏幕内提供实际的图像存在效果。可以有按钮、面板、滑动条等几乎所有UI的背景。

- Source Image: 不选就只有颜色
- Color: 控制UI的颜色
- Material: 一般可以为空
- Image Type: 影响源图像的使用方式
	- Simpley: sprite会拉伸来满足rect transform的大小。 Preserve Aspect选项表示图像会在边界范围内尽可能放大，但是会保持导入时的宽高比。
	- Sliced: 图片将使用9分方式显示，边界不拉伸，只有中心拉伸。
	- Tiled: 拼贴原图，就是平铺。
	- Filled: 可以控制填充的起始位置，可以做血条或则汽车速度表。
	
## 5 text

用于在UI内渲染文字。

