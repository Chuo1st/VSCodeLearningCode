/**
 * 目标：网站-更换背景
 *  1. 选择图片上传，设置body背景
 *  2. 上传成功时，"保存"图片url网址
 *  3. 网页运行后，"获取"url网址使用
 * */

const body = document.querySelector('body')
body.style.backgroundImage = `url(${localStorage.getItem('backgroundImg')})`
const changeDiv = document.querySelector('.right')
changeDiv.addEventListener('change', (e)=>{
    if (e.target.tagName === 'INPUT')
    {
        // 获取图片
        const pic = new FormData()
        pic.append('img', e.target.files[0])
        axios({url:'http://hmajax.itheima.net/api/uploadimg', method:'post', data:pic}).then((res)=>{
            console.log(res)
            document.body.style.backgroundImage = `url(${res.data.data.url})`
            localStorage.setItem('backgroundImg', res.data.data.url)
        }).catch((err)=>{
            alert(err)
        })
    }
})