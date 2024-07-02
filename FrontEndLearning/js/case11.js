// 默认都是未勾选
const selectAll = document.querySelector('#checkAll')
const ckList = document.querySelectorAll('.ck')
selectAll.addEventListener('click', ()=>{
    for (let i = 0; i < ckList.length; ++i)
    {
        ckList[i].checked = selectAll.checked
    }
})

for (let i = 0; i < ckList.length; ++i)
{
    ckList[i].addEventListener('click',()=>{
        selectAll.checked = document.querySelectorAll('.ck:checked').length === 3
    })
}