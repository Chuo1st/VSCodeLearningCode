// 顶部当行模块
const header = document.querySelector('xtx_header')
const html = document.documentElement
const wrapper = document.querySelector('xtx-wrapper')
html.addEventListener('scroll', ()=>{
    if (this.scrollTop >= wrapper.offsetHeight)
    {

    }
})

// 图片右侧框模块
const divSmall = document.querySelector('.small')
const divMiddle = document.querySelector('.middle')
divMiddle.addEventListener('mouseenter', ShowHide)
divMiddle.addEventListener('mouseleave', ShowHide)
const divLarge = document.querySelector('.large')
divSmall.addEventListener('mousemove', (e)=>{
    if (e.target.tagName === 'IMG')
    {
        document.querySelector('.active').classList.remove('active')
        e.target.parentNode.classList.add('active')
        document.querySelector('.middle').children[0].src = e.target.src
        divLarge.style.backgroundImage = `url(${e.target.src})`
    }
})

// 大盒子的显示和隐藏
function ShowHide()
{
    let timerID
    if (divLarge.style.display ==='' || divLarge.style.display === 'none')
    {
        clearTimeout(timerID)
        divLarge.style.display = 'block'
    }
    else
    {
        timerID = setTimeout(() => {
            divLarge.style.display = 'none'
        }, 200);
    }
}

// 颜色尺寸模块
const dd = document.querySelector('.dd')

// 数量模块
const num = document.querySelector('.num')
num.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        if (e.target.innerHTML === '-')
        {
            let count = +e.target.nextElementSibling.value
            if (count === 1)
            {
                return
            }
            e.target.nextElementSibling.value = --count
        }else{
            let count = +e.target.previousElementSibling.value
            e.target.previousElementSibling.value = ++count
        }
    }
})

// 放大镜模块
const blackBlock = document.querySelector('.layer')
divMiddle.addEventListener('mouseenter', BlackBlockShowHide)
divMiddle.addEventListener('mouseleave', BlackBlockShowHide)
function BlackBlockShowHide()
{
    if (blackBlock.style.display === '' || blackBlock.style.display === 'none')
    {
        blackBlock.style.display = 'block'
    }
    else{
        blackBlock.style.display = 'none'
    }
}

// 放大镜主要算法
divMiddle.addEventListener('mousemove', BlackBlockMove)
// 先获取中盒子的坐标范围
const left = divMiddle.offsetLeft
const right = left + divMiddle.clientWidth
const up = divMiddle.offsetHeight
const down = up + divMiddle.clientHeight
function BlackBlockMove()
{
    // 判断鼠标是否在盒子的范围
}