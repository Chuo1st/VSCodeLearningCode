// 登录方式模块
const logButton = document.querySelector('.tab-nav').children[0]
const logPanel = document.querySelector('.box').children[1]
const codeButton = document.querySelector('.tab-nav').children[1]
const codePanel = document.querySelector('.box').children[2]
logButton.addEventListener('click', ()=>{
    if (!logButton.classList.contains('active'))
    {
        logButton.classList.add('active')
        codeButton.classList.remove('active')
        logPanel.style.display = 'block'
        codePanel.style.display = 'none'
    }
})
codeButton.addEventListener('click', ()=>{
    if (!codeButton.classList.contains('active'))
    {
        logButton.classList.remove('active')
        codeButton.classList.add('active')
        logPanel.style.display = 'none'
        codePanel.style.display = 'block'
    }
})

// 验证码模块
const link = document.querySelector('.link')
let isIdentifying = false
link.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        if (!isIdentifying)
        {
            isIdentifying = true
            let secondCount = 5
            e.target.innerHTML = `0${secondCount}后重新发送验证码`
            let timerID = setInterval(()=>{
                --secondCount
                if (secondCount === 0)
                {
                    e.target.innerHTML = '重新发送'
                    clearInterval(timerID)
                    isIdentifying = false
                    return
                }
                e.target.innerHTML = `0${secondCount}后重新发送验证码`
            }, 1000)
        }
    }
})

// 用户名称或手机号模块
const inputUserName = document.querySelector('[name=username]')
// 密码模块
const inputPasswd = document.querySelector('password')
// 登录按钮模块
const checkbox = document.querySelector('.remember')
// 获取表单
const form = document.querySelector('form')
form.addEventListener('submit', (e)=>{
    e.preventDefault()
    if (!checkbox.checked)
    {
        alert('请勾选同意协议')
        return
    }
    window.localStorage.setItem('usrname', inputUserName.value)
    location.href = './index.html'
})
