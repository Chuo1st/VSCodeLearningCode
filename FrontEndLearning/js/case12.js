const header = document.querySelector('.header')
const html = document.documentElement
const edge = document.querySelector('.sk')
window.addEventListener('scroll', ()=>{
    if (html.scrollTop >= edge.offsetTop)
    {
        header.style.top = ' 0px'
    }else{
        header.style.top = '-80px'
    }
})