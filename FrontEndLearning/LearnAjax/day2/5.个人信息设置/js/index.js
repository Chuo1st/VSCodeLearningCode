/**
 * 目标1：信息渲染
 *  1.1 获取用户的数据
 *  1.2 回显数据到标签上
 * */

// 获取本地存储数据，先吧json转换为js复杂类型，该类型的属性对应的就是input的class
const localData = JSON.parse(localStorage.getItem('localdata'))
const url = localStorage.getItem('avatar')
const avatar = url ===  null ? null : `url(${url})`
render(localData)

function render(data, av)
{
    // 遍历data的属性，从而找到相对应的input的dom对象
    if (data)
    {
        const keys = Object.keys(data)
        for (let i = 0; i < keys.length; ++i)
        {
            const input = document.querySelector(`.${keys[i]}`)
            input.value = data[keys[i]]
        }
    }

    if (av)
    {
        const imgBox = document.querySelector('.prew')
        imgBox.src = av
    }
}

// 头像设置模块
const changeAvatarDom = document.querySelector('.upload')
changeAvatarDom.addEventListener('change', (e)=>{
    // 获取图片
    const
    const selectedAvatar = e.target.files[0] 
})
