let courses = [
    {
        src: '../source/case3_images/course01.png',
        title: 'Think PHP 5.0 博客系统实战项目演练',
        num: 1125
    },
    {
        src: '../source/case3_images/course02.png',
        title: 'Android 网络动态图片加载实战',
        num: 357
    },
    {
        src: '../source/case3_images/course03.png',
        title: 'Angular2大前端商城实战项目演练',
        num: 22250
    },
    {
        src: '../source/case3_images/course04.png',
        title: 'AndroidAPP实战项目演练',
        num: 389
    },
    {
        src: '../source/case3_images/course05.png',
        title: 'UGUI源码深度分析案例',
        num: 124
    },
    {
        src: '../source/case3_images/course06.png',
        title: 'Kami2首页界面切换效果实战演练',
        num: 432
    },
    {
        src: '../source/case3_images/course07.png',
        title: 'UNITY 从入门到精通实战案例',
        num: 888
    },
    {
        src: '../source/case3_images/course08.png',
        title: 'Cocos 深度学习你不会错过的实战',
        num: 590
    },
    {
        src: '../source/case3_images/course04.png',
        title: '自动添加的模块',
        num: 1000
    }
]

document.write('<ul class = "clearfix">')
for (i = 0; i < courses.length; ++i)
{
    document.write(`
            <li>
            <a rel="#">
                <img src=${courses[i].src} title=${courses[i].title}>
                <h4>${courses[i].title}</h4>
                <div class="info">
                    <span>高级·</span>
                    <span>${courses[i].num}</span>
                    在学习
                </div>
            </a>
        </li>
    `)
}
document.write('</ul>')

