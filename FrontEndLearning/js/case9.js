const textArea = document.querySelector('#tx')
const total = document.querySelector('.wrapper .total')

textArea.addEventListener('focus', ()=>{
    total.style.opacity = 1
})

textArea.addEventListener('blur', ()=>{
    total.style.opacity = 0
})

textArea.addEventListener('input', (e)=>{
    total.innerHTML = `${textArea.value.length}/200`
})

textArea.addEventListener('keyup', (e)=>{
    if (e.key.trim().length > 0)
    {
        if (e.key === 'Enter')
            Comment()
    }
})

const button = document.querySelector('.wrapper button')
button.addEventListener('click', ()=>{
    if (textArea.value.trim().length > 0)
    {
        Comment()
    }
})

const item = document.querySelector('.list .item')
const commentText = document.querySelector('.list .item .text')
function Comment()
{
    item.style.display  = 'block'
    commentText.innerHTML = `${textArea.value}`
    textArea.value = ''
}

