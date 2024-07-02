// 验证码模块
const identifyButton = document.querySelector('.xtx-form-item .code')
let isIdentifying = false
identifyButton.addEventListener('click', (e)=>{
    if (!isIdentifying)
    {
        let secondCount = 5
        isIdentifying = true
        e.target.innerHTML = `0${secondCount}秒后重新获取`
        let timerID = setInterval(()=>{
            --secondCount
            if (secondCount === 0)
            {
                clearInterval(timerID)
                identifyButton.innerHTML = '重新发送'
                isIdentifying = false
                return
            }
            identifyButton.innerHTML = `0${secondCount}秒后重新获取`
        }, 1000)
    }
})

// 验证用户名模块
const inputName = document.querySelector('[name=username]')
inputName.addEventListener('change', verifyName)

function verifyName()
{
    const reg = /^[a-zA-Z0-9-_]{6,10}$/
    if (!reg.test(inputName.value))
    {
        inputName.nextElementSibling.innerHTML = '输入不合法'
        return false
    }
    inputName.nextElementSibling.innerHTML = ''
    return true
}

// 验证手机号模块
const inputPhoneNumber = document.querySelector('[name=phone]')
inputPhoneNumber.addEventListener('change', verifyPhoneNumber)

function verifyPhoneNumber()
{
    const reg = /^1(3\d|4[5-9]|5[0-35-9]6[567]|7[0-8]|8\d|9[0-35-9])\d{8}$/
    if (!reg.test(inputPhoneNumber.value))
    {
        inputPhoneNumber.nextElementSibling.innerHTML = '输入不合法'
        return false
    }
    inputPhoneNumber.nextElementSibling.innerHTML = ''
    return true
}

// 密码模块
const inputPasswdNumber = document.querySelector('[name=password]')
inputPasswdNumber.addEventListener('change', verifyPasswd)

function verifyPasswd()
{
    const reg = /^[\d\w-_]{6,20}$/
    if (!reg.test(inputPasswdNumber.value))
    {
        inputPasswdNumber.nextElementSibling.innerHTML = '输入不合法'
        return false
    }
    inputPasswdNumber.nextElementSibling.innerHTML = ''
    return true
}

// 密码验证二次确认
const inputPasswdConfirm = document.querySelector('[name=confirm]')
inputPasswdConfirm.addEventListener('change', PasswdConfirm)

function PasswdConfirm()
{
    if (!(inputPasswdConfirm.value === inputPasswdNumber.value))
    {
        inputPasswdConfirm.nextElementSibling.innerHTML = '两次密码输入不一致'
        return false
    }
    inputPasswdConfirm.nextElementSibling.innerHTML = ''
    return true
    
}

// 点击用户协议模块
const agreeIcon = docuemtn.querySelector('.pl50')
agreeIcon.addEventListener('click', ()=>{
    agreeIcon.classList.toggle('icon-queren2')
})