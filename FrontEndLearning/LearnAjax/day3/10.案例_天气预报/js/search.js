// 搜索模块: 输入控件每当感知到输入，输入事件检查当前value的长度，大于0就显示下拉框，否则隐藏，然后下拉框添加点击事件。。。

const searchInput = document.querySelector('.search-city')
searchInput.addEventListener('input', (e) =>{
  const searchList = document.querySelector('.search-list')
  searchInput.display = 'block'
})