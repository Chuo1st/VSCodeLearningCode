const initData = [
    {
      stuId: 1,
      uname: '迪丽热巴',
      age: 22,
      salary: '12000',
      gender: '女',
      city: '北京',
      time: '2099/9/9 08:08:08'
    }
]

// 先加载本地存储
if (localStorage.getItem('initData') === null)
{
    localStorage.setItem('initData', JSON.stringify(initData))
}
const studentArray = JSON.parse(localStorage.getItem('initData')) || []
const form = document.querySelector('.info')
const dataCount = document.querySelector('.title span')
const tbody = document.querySelector('tbody')
Render()

// 录入
const inputName = document.querySelector('.uname')
const inputAge = document.querySelector('.age')
const inputSal = document.querySelector('.salary')

form.addEventListener('submit', (e)=>{
    e.preventDefault()
    if (inputAge.value && inputName.value && inputSal.value)
    {
        studentArray.push({
            stuId: studentArray.length + 1,
            uname:inputName.value,
            age:inputAge.value,
            gender:document.querySelector('.gender').value,
            salary:inputSal.value,
            city:document.querySelector('.city').value,
            time:new Date().getDate()
        })
        form.reset()
        Render()
        localStorage.setItem('initData', JSON.stringify(studentArray))
    }
    else
    {
        alert('请完整填写讯息')
    }
})

// 删除
tbody.addEventListener('click', (e)=>{
    if (e.target.tagName === 'A')
    {
        if (confirm('确定要删除该行数据吗'))
        {
            const rowIndex = e.target.parentNode.parentNode.rowIndex
            studentArray.splice(rowIndex - 1, 1)
            localStorage.setItem('initData', JSON.stringify(studentArray))
            Render()
        }
    }
})


function Render()
{
    const student = studentArray.map(function(ele, index){
        return `<tr>
                    <th>${ele.stuId}</th>
                    <th>${ele.uname}</th>
                    <th>${ele.age}</th>
                    <th>${ele.gender}</th>
                    <th>${ele.salary}</th>
                    <th>${ele.city}</th>
                    <th>${ele.time}</th>
                    <th>
                        <a href="javascript:">
                        <i class="iconfont icon-shanchu"></i>
                        删除
                    </th>
                </tr>`
    })
    tbody.innerHTML = student.join('')
    dataCount.innerHTML = `${studentArray.length}`
}