// 1.实现导航显示（到达xtx-entry后再显示） 2.实现导航按钮功能
const html = document.documentElement
const entry = document.querySelector('.xtx_entry')
const elevator = document.querySelector('.xtx-elevator')
window.addEventListener('scroll', ()=>{
    const n = html.scrollTop
    if (n >= entry.offsetTop)
    {
        elevator.style.opacity = 1
    }else{
        elevator.style.opacity = 0
    }
})

elevator.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        const active = document.querySelector('.xtx-elevator-list .active')
        if (active)
            active.classList.remove('active')
        if (!e.target.dataset.name)
        {
            html.scrollTop = 0
            return
        }
        e.target.classList.add('active')
        const panel = document.querySelector(`.xtx_goods_${e.target.dataset.name}`)
        html.scrollTop = panel.offsetTop
    }
})
const edge1 = document.querySelector('.xtx_goods_new')
const edge2 = document.querySelector('.xtx_goods_popular')
const edge3 = document.querySelector('.xtx_goods_brand')
const edge4 = document.querySelector('.xtx_goods_category')
const edge5 = document.querySelector('.xtx_goods_topic')

window.addEventListener('scroll', ()=>{
    debugger
    const active = document.querySelector('.active')
    if (active)
        active.classList.remove('active')
    if (html.scrollTop >= edge1.offsetTop)
    {
        if (html.scrollTop >= edge2.offsetTop)
        {
            if (html.scrollTop >= edge3.offsetTop)
            {
                if (html.scrollTop >= edge4.offsetTop)
                {
                    document.querySelector('[data-name=topic]').classList.add('active')
                }else{
                    document.querySelector('[data-name=brand]').classList.add('active')
                }
            }else{
                document.querySelector('[data-name=popular]').classList.add('active')
            }
        }else{
            document.querySelector('[data-name=new]').classList.add('active')
        }
    }
})

