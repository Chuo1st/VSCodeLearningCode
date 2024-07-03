/**
 * 目标1：渲染图书列表
 *  1.1 获取数据
 *  1.2 渲染数据
 */

const creator = 'hzx'
const table = document.querySelector('.list')
const addButton = document.querySelector('.plus-btn')
const saveButton = document.querySelector('.add-btn')
// bootstrap弹窗对象
const modalDom = document.querySelector('.add-modal')
const modal = new bootstrap.Modal(modalDom)
renderTable()

// 添加添加按钮事件
addButton.addEventListener('click', ()=>{
    modal.show()

})
saveButton.addEventListener('click', ()=>{
    const addForm = document.querySelector('.add-form')
    // 获取表单内容
    const addData = serialize(addForm, {hash:true, empty:true})
    axios({url:'http://ajax-api.itheima.net/api/books' ,method:'post' ,data:{
        bookname:addData.bookname, author:addData.author, publisher:addData.publisher
    }})
    .then(res =>{
            renderTable()
    })
    .catch(error =>{
        alert('添加失败')
    })
    modal.hide()
})

// 添加删除和编辑事件
const editButton = document.querySelector('.edit-btn')
const editModalDom = document.querySelector('.edit-modal')
const editModal = new bootstrap.Modal(editModalDom)
editButton.addEventListener('click', ()=>{
    // 通过form-serialze获取所有input的讯息
    const editForm = document.querySelector('.edit-form')
    const {id, bookname, author, publisher} = serialize(editForm, {hash:true, empty:true})
    axios({url:`http://ajax-api.itheima.net/api/books/${id}`, method:'put', data:{id, bookname, author, publisher}}).then(res=>{
        editModal.hide()
        renderTable()
    }).catch(err=>{
        editModal.hide()
        alert(err)
    })
})
table.addEventListener('click', (e)=>{
    if (e.target.tagName === 'SPAN')
    {
        if (e.target.innerHTML === '删除')
        {
            const id = e.target.parentNode.parentNode.children[0].innerHTML
            axios({url:`http://ajax-api.itheima.net/api/books/${id}`, method:'delete'})
            .then(res =>{
                renderTable()
            })
            .catch(error =>{
                alert(error)
            })
        }
        else{
            // 编辑
            // 不应该从页面中获取书本的信息，因为有可能页面的信息没刷新，但是在服务器中已经改变了，所以先通过id获取服务器中书本的信息
            const id = e.target.parentNode.parentNode.children[0].innerHTML
            axios({url:`http://ajax-api.itheima.net/api/books/${id}`}).then(res=>{
                // (把数据填进editmodal中，先获取所有输入框的dom
                // 输入框的属性对应的也是res的属性，所以我们可以通过res的属性名循环获取input的dom
                const keys = Object.keys(res.data.data)
                for (let i = 0; i < keys.length; ++i)
                {
                    document.querySelector(`.edit-modal .${keys[i]}`).value = res.data.data[keys[i]]
                }
                editModal.show()
            }).catch(err=>{
                alert(err)
            })
        }
    }
})

// 渲染函数
function renderTable()
{
    axios({url:'http://ajax-api.itheima.net/api/books'})
    .then((result) => {
        const bookList = result.data.data.map((item, index)=>{
            return `<tr>
            <td>${item.id}</td>
            <td>${item.bookname}</td>
            <td>${item.author}</td>
            <td>${item.publisher}</td>
            <td>
              <span class="del">删除</span>
              <span class="edit">编辑</span>
            </td>
          </tr>`
        }).join('')
        table.innerHTML = bookList
    })
    .catch((err) => {
        alert(err)
    });
}
