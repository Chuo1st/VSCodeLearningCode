
// 1. 搜索模块: 输入控件每当感知到输入，输入事件检查当前value的长度，大于0就显示下拉框，否则隐藏，然后下拉框添加点击事件。。。

// 获取所有城市名: 先通过获取所有省份，然后获取所有省份的城市
const citys = new Array()
myAxios({ url: "https://hmajax.itheima.net/api/province" }).then(res => {
  const provinces = res.list.map((province, index) => {
    myAxios({ url: 'https://hmajax.itheima.net/api/city', params: { pname: province } }).then(res => {
      for (let i = 0; i < res.list.length; ++i)
      {
        citys.push(decodeURIComponent(res.list[i]))
      }
    })
  })

}).catch(err => {
  console.log(err)
})
console.log(citys)

// 为输入框添加输入事件
const searchInput = document.querySelector('.search-city')
searchInput.addEventListener('input', (e) => {
  // 判断当前搜索框是否有输入字符，没有内容无需渲染下拉框
  const searchList = document.querySelector('.search-list')
  if (e.target.value.length > 0)
  {
    // 通过判断输入的内容，用正则表达式筛选数组中的城市，然后把城市渲染到searchList中
    const reg = new RegExp(e.target.value + '+') // 该正则表达式表示出现一次或者更多次
    renderSearchList(searchList, citys, reg)
    searchList.style.display = 'block'
  } else {
    searchList.style.display = 'none'
  }
})

function renderSearchList(searchListDom, cityNames, reg)
{
  let newHTML = ''
  for (let i = 0; i < cityNames.length; ++i)
  {
    if (reg.test(cityNames[i]))
    {
      newHTML += `<li class="city-item">${cityNames[i]}</li>`
    }
  }
  searchListDom.innerHTML = newHTML
  console.log(newHTML)
}