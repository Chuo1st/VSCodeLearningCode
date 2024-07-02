/*
    鼠标未进入wrapper时，定时器会轮播图片，反之会停止轮播
    当鼠标进入到a的区域，会转换到对应的图片
*/

// 获取元素
const aList = document.querySelectorAll('.tab-nav a')
const divList = document.querySelectorAll('.tab-content .item')
const wrapper = document.querySelector('.tab')
let a = aList[0]
let div = divList[0]
const count = aList.length

// 设定定时器
let index = 0
let timerID = setInterval(() => {
    OnTimer()
}, 668)

// 鼠标进入wrapper和离开wrapper的事件注册
wrapper.addEventListener('mouseenter', ()=>{
    clearInterval(timerID)
})

wrapper.addEventListener('mouseleave', ()=>{
    timerID = setInterval(() => {
        OnTimer()
    }, 888)
})

// 优化：之前需要循环注册所有的li的事件，
const ul = document.querySelector('ul')
ul.addEventListener('click', (e)=>{
    if (e.target .tagName === 'A')
    {
        a.classList.remove('active')
        e.target.classList.add('active')
        a = e.target
        div.classList.remove('active')
        const id = +e.target.dataset.id
        div = divList[`${id - 1}`]
        div.classList.add('active')
        index = id - 1
    }
})


// 定时器任务
function OnTimer()
{
    ++index
    if (index >= count)
    {
        index = 0
    }
    a.classList.remove('active')
    a = aList[index]
    a.classList.add('active')

    div.classList.remove('active')
    div = divList[index]
    div.classList.add('active')
}
