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
	- 当UI元素在local空间编辑时，矩形和操作点与UI元素对齐
	- 当UI元素在global空间编辑时，矩形和操作点全局对齐