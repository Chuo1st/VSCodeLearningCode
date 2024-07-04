/**
 * 目标1：信息渲染
 *  1.1 获取用户的数据
 *  1.2 回显数据到标签上
 * */

// 渲染表单
function render()
{
    axios({url:'https://hmajax.itheima.net/api/settings', params:{creator:'chuo'}}).then(result => {
        console.log(result)
        const data = result.data.data
        Object.keys(data).forEach(key =>{
            if (key === 'avatar')
            {
                const prew = document.querySelector('.prew')
                prew.src = data[key]
            }
            else if (key === 'gender')
            {
                const ratioButtons = document.querySelectorAll('.gender')
                console.log(ratioButtons)
                ratioButtons[data[key]].checked = true
            }
            else{
                const inputDom = document.querySelector(`.${key}`)
                inputDom.value = data[key]
            }
        })
    }).catch(err =>{
        console.log(err)
    })
}
render()

// 获取提示框
const toastDom = document.querySelector()
const toast = new bootstrap.Toast(toastDom)
funtion toastShow(message, isSuccessfully)
{
    if (isSuccessfully)
    {
        toastDom.className = "alert alert-success"
    }else{
        toastDom.className = "alert alert-danger"
    }
}

// 头像上传模块
const uploadBtn = document.querySelector('.upload')
uploadBtn.addEventListener('change', e => {
    const pic = new FormData()
    pic.append('avatar', e.target.files[0])
    pic.append('creator', 'chuo')
    axios({url:'https://hmajax.itheima.net/api/avatar', method:'put', data:pic}).then(result => {
        const prew = document.querySelector('.prew')
        prew.src = result.data.data.avatar
    }).catch(err => console.log(err))
})

// 修改个人信息
const submitBtn = document.querySelector('.submit')
submitBtn.addEventListener('click', () => {
    const form = document.querySelector('.user-form')
    const data = serialize(form, {hash:true, empty:true})
    axios({url:'https://hmajax.itheima.net/api/settings', method:'put', data:{desc:data.desc, email:data.email, gender:+data.gender, nickname:data.nickname, creator:'chuo'}}).then(result => {
        console.log(result)
    }).catch(err => console.log(err))
})
