    // 1. 初始数据
    const sliderData = [
        { url: '../source/case5_images/slider01.jpg', title: '对人类来说会不会太超前了？', color: 'rgb(100, 67, 68)' },
        { url: '../source/case5_images/slider02.jpg', title: '开启剑与雪的黑暗传说！', color: 'rgb(43, 35, 26)' },
        { url: '../source/case5_images/slider03.jpg', title: '真正的jo厨出现了！', color: 'rgb(36, 31, 33)' },
        { url: '../source/case5_images/slider04.jpg', title: '李玉刚：让世界通过B站看到东方大国文化', color: 'rgb(139, 98, 66)' },
        { url: '../source/case5_images/slider05.jpg', title: '快来分享你的寒假日常吧~', color: 'rgb(67, 90, 92)' },
        { url: '../source/case5_images/slider06.jpg', title: '哔哩哔哩小年YEAH', color: 'rgb(166, 131, 143)' },
        { url: '../source/case5_images/slider07.jpg', title: '一站式解决你的电脑配置问题！！！', color: 'rgb(53, 29, 25)' },
        { url: '../source/case5_images/slider08.jpg', title: '谁不想和小猫咪贴贴呢！', color: 'rgb(99, 72, 114)' },
      ]


  // 鼠标光标进入图片框，停止定时器，光标离开图片框就启动定时器，还有左右按钮的实现
      const img = document.querySelector('.slider-wrapper img')
      const p = document.querySelector('.slider-footer p')
      const footer = document.querySelector('.slider-footer')
      let curLi = null
      let index = 0
      
      // 定时器任务
      function TimerTask()
      {
        document.querySelector('.slider-indicator .active').classList.remove('active')
        curLi = document.querySelector(`.slider-indicator li:nth-child(${index + 1})`)
        curLi.classList.add('active')
        img.src = sliderData[index].url
        p.innerHTML = sliderData[index].title
        footer.style.backgroundColor = sliderData[index].color
      }

      // 启动定时器
      let timerID = setInterval(()=>{
        ++index
        if (index >= sliderData.length)
        {
          index = 0
        }
        TimerTask()
      }, 1000)

      // 设置鼠标光标事件
      const div = document.querySelector('.slider')
      div.addEventListener('mouseenter', ()=>{clearInterval(timerID)})
    
      div.addEventListener('mouseleave',()=>{
        timerID = setInterval(() => {
          ++index
          if (index >= sliderData.length)
          {
            index = 0
          }
          TimerTask()
        }, 1000);
      })

      // 按钮事件触发函数

      // 后退按钮事件
      const btnPrev = document.querySelector('.prev')
      btnPrev.addEventListener('click', ()=>{
        --index;
        if (index < 0)
        {
          index = sliderData.length - 1
        }
        TimerTask()
      })

      // 前进按钮事件
      const btnNext = document.querySelector('.next')
      btnNext.addEventListener('click', ()=>{
        ++index
        if (index >= sliderData.length)
        {
          index = 0
        }
        TimerTask()
      })