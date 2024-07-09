/*
// 存放一级分类的数组
const topCategory = new Array()
// 存放promise数组
const promises = new Array()
axios({url:'https://hmajax.itheima.net/api/category/top'}).then(result => {
    // 获取所有一级分类
    console.log(result)
    const kinds = result.data.data
    for (let i = 0; i < kinds.length; ++i)
    {
        topCategory.push({id:kinds[i].id, name:kinds[i].name, picture:kinds[i].picture})
    }

    // 获取二级分类，需要多个promise，利用Promise静态方法all实现 (下面代码的过程不可以在外面执行，因为同步代码会比AJAX请求完成事件先执行，所以外面执行的同步代码获取到的topCategory和promises是为空的)
    for (let i = 0; i < topCategory.length; ++i)
    {
        promises.push(axios({url:'https://hmajax.itheima.net/api/category/sub', params:{id:`${topCategory[i].id}`}}))
    }

    // 全部promise一起执行
    Promise.all(promises).then(result => {
        // 渲染所有一级和二级分类
        console.log(result)
        renderContainer(result)
    }).catch(error => {
        console.log(new Error(error))
    })
}).catch(err => {
    console.log(err)
})

// 渲染函数
function renderContainer(result)
{
    const container = document.querySelector('.sub-list')
    container.innerHTML = ''
    for (let i = 0; i < result.length; ++i)
    {
        // 由于每个分类的二级分类的数量不同，所以采用这中方法动态渲染页面
        const itemDom = document.createElement('DIV')
        // 一级分类标题
        const header = document.createElement('H3')
        header.innerHTML = `${topCategory[i].name}`
        // 二级分类列表
        const ul = document.createElement('UL')
        let ulInnerHTML = ''
        const children = result[i].data.data.children
        for (let j = 0; j < children.length; ++j)
        {
            ulInnerHTML += `<li>
            <a href="javascript:;">
              <img src=${children[j].picture}>
              <p>${children[j].name}</p>
            </a>
          </li>`
        }
        ul.innerHTML = ulInnerHTML
        // 把一级分类和二级分类添加到容器中
        itemDom.appendChild(header)
        itemDom.appendChild(ul)
        // 把item容器添加到主容器containner中
        container.appendChild(itemDom)
    }

}
*/

// 第二版
axios({url:'https://hmajax.itheima.net/api/category/top'}).then(result => {
    console.log(result)
    const promises = result.data.data.map(topCategory => {
        return axios({url:'https://hmajax.itheima.net/api/category/sub', params:{id:topCategory.id}})
    })

    Promise.all(promises).then(result => {
        console.log(result)
        const sublistDom = document.querySelector('.sub-list')
        let innerhtml = ''
        result.map(ele => {
            innerhtml += `<div class="item">
            <h3>${ele.data.data.name}</h3>
            <ul>
            ${ele.data.data.children.map((secondCategory) =>{
                return `              <li>
                <a href="javascript:;">
                  <img src=${secondCategory.picture}}>
                  <p>${secondCategory.name}</p>
                </a>
              </li>`
            }).join()}
            </ul>
          </div>`
        })
        sublistDom.innerHTML = innerhtml
    }).catch(err => console.log(err))

}).catch(err => console.log(err))