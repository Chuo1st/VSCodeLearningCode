const input = document.querySelector('input')
const list = document.querySelector('.result-list')
input.addEventListener('focus', ()=>{
    list.style.display = 'block'
    input.classList.add('search')
})

input.addEventListener('blur', ()=>{
    list.style.display = 'none'
    input.classList.remove('search')
})