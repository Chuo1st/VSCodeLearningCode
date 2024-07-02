const tabsList = document.querySelector('.tabs-list')
const line = document.querySelector('.line')
tabsList.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        const offsetLeft = e.target.offsetLeft
        line.style.transform = `translateX(${offsetLeft}px)`
    }
})