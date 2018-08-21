/*
* 使用对象存储整个棋盘，位置作key，棋子类型作value
*
* 鼠标点击
* ↓
* 判断是第几次点击->第二次点击=上传服务器
* ↓（第一次）
* 确定点击位置
* ↓
* 转换为两个整数的序列
* ↓
* 检测是否有棋子->没有=不操作
* ↓
* 有棋子=让棋子闪烁，等待第二次点击
*
*
* */
'use strict';

//原始棋盘
const ofiled3 = [
    149, 259, 339, 469, 529, 679, 719, 1089, 1109,
    877, 917, 1286, 1366, 1446, 1526, 1606,

    1740, 1850, 1930, 2060, 2120, 2270, 2310, 2680, 2700,
    2472, 2512, 2883, 2963, 3043, 3123, 3203
];

//棋盘位置对应的css，竖屏
const xrange = ['0.5', '11.5', '22.5', '33.5', '44.5', '55.5', '66.5', '77.5', '88.5'];
const yrange = ['0', '11', '22', '33', '44', '55', '66', '77', '88', '99'];
//方屏
const xrange2 = ['0', '10', '20', '30', '40', '50', '60', '70', '80'];
const yrange2 = ['0', '10', '20', '30', '40', '50', '60', '70', '80', '90'];

//piece存储转id
function pic2id(pic) {
    return Math.floor(pic / 100);
}

//piece存储转pos
function pic2pos(pic) {
    return pic % 100;
}

//按钮初始化 for 竖屏
function btnInit1() {
    let htmlStr = "";
    for (let i = 0; i <= 89; i += 1) {//放入按钮
        htmlStr += '<img src="pic/blank.svg" class="btn" id="btn' + i + '" onclick="clickBtn(' + i + ')">\n';
    }
    document.getElementById('btns').innerHTML = htmlStr;
    for (let i = 0; i <= 89; i += 1) {//按钮位置摆放
        document.getElementById('btn' + i).style.top = yrange[pos2y(i)] + 'vw';//根据i计算出应该在的位置
        document.getElementById('btn' + i).style.left = xrange[pos2x(i)] + 'vw';
    }
}

//按钮初始化 for 方屏
function btnInit2() {
    let htmlStr = "";
    for (let i = 0; i <= 89; i += 1) {
        htmlStr += '<img src="pic/blank.svg" class="btn" id="btn' + i + '" onclick="clickBtn(' + i + ')">\n';
    }
    document.getElementById('btns').innerHTML = htmlStr;
    for (let i = 0; i <= 89; i += 1) {
        document.getElementById('btn' + i).style.top = yrange2[pos2y(i)] + 'vh';
        document.getElementById('btn' + i).style.left = xrange2[pos2x(i)] + 'vh';
    }
}

//按钮初始化 for 宽屏
function btnInit3() {
    let htmlStr = "";
    for (let i = 0; i <= 89; i += 1) {
        htmlStr += '<img src="pic/blank.svg" class="btn" id="btn' + i + '" onclick="clickBtn(' + i + ')">\n';
    }
    document.getElementById('btns').innerHTML = htmlStr;
    for (let i = 0; i <= 89; i += 1) {
        document.getElementById('btn' + i).style.top = yrange2[pos2y(i)] + 'vh';
        document.getElementById('btn' + i).style.left = 'calc(50vw - 50vh * 900 / 1000 + ' + xrange2[pos2x(i)] + 'vh)';
    }
}

//封装id和pos
function pi2pic(pos, id) {
    return 100 * id + pos;
}

//xy转pos
function xy2pos(x, y) {
    return 10 * x + y;
}

//pos转x
function pos2x(pos) {
    return Math.floor(pos / 10);
}

//pos转y
function pos2y(pos) {
    return pos % 10;
}

//清除渲染内容
function clearRende() {
    //遍历,r1-r7,b1-b7
    document.getElementById('r1').style.visibility = 'hidden';
    document.getElementById('b1').style.visibility = 'hidden';
    for (let i = 2; i <= 6; i += 1) {
        document.getElementById('r' + i + '1').style.visibility = 'hidden';
        document.getElementById('r' + i + '2').style.visibility = 'hidden';
        document.getElementById('b' + i + '1').style.visibility = 'hidden';
        document.getElementById('b' + i + '2').style.visibility = 'hidden';
    }
    for (let i = 1; i <= 5; i += 1) {
        document.getElementById('r7' + i).style.visibility = 'hidden';
        document.getElementById('b7' + i).style.visibility = 'hidden';
    }
}

//渲染
//竖屏
function rende(theFiled) {
    let pos = 90;
    //遍历棋子
    for (let i = 0; i <= 31; i += 1) {
        pos = pic2pos(theFiled[i]);
        if (pos == 90) {//隐藏
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'hidden';
        }
        else {//渲染
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingTop = yrange[pos2y(pos)] + 'vw';
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingLeft = xrange[pos2x(pos)] + 'vw';
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'visible';
        }
    }
}

//方屏
function rende2(theFiled) {
    let pos = 90;
    //遍历棋子
    for (let i = 0; i <= 31; i += 1) {
        pos = pic2pos(theFiled[i]);
        if (pos == 90) {//隐藏
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'hidden';
        }
        else {//渲染
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingTop = yrange2[pos2y(pos)] + 'vh';
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingLeft = xrange2[pos2x(pos)] + 'vh';
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'visible';
        }
    }
}

function rende3(theFiled) {
    let pos = 90;
    //遍历棋子
    for (let i = 0; i <= 31; i += 1) {
        pos = pic2pos(theFiled[i]);
        if (pos == 90) {//隐藏
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'hidden';
        }
        else {//渲染
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingTop = yrange2[pos2y(pos)] + 'vh';
            document.getElementById('p' + pic2id(theFiled[i])).style.paddingLeft = 'calc(50vw - 50vh * 900 / 1000 + ' + xrange2[pos2x(pos)] + 'vh)';
            document.getElementById('p' + pic2id(theFiled[i])).style.visibility = 'visible';
        }
    }
}

//获取棋子位置
function getPosById(theFiled, theId) {
    if (theFiled.length != 32 || theId < 1 || theId > 32)
        return null;
    //遍历比较
    const tmp1 = theId * 100;
    const tmp2 = tmp1 + 99;
    for (let i = 0; i <= 31; i += 1) {
        if (tmp1 <= theFiled[i] && tmp2 >= theFiled[i])//找到
            return pic2pos(theFiled[i]);
    }
}

//从位置读取id
function getIdByPos(theFiled, thePos) {
    return pic2id(theFiled[getPtrByPos(theFiled, thePos)]);
}

//判断位置上是否有棋子
function isPiece(theFiled, thePos) {
    //遍历theFiled中的棋子
    for (let i = 0; i <= 31; i += 1) {
        if (pic2pos(theFiled[i]) == thePos)
            return true;
    }
    return false;
}

//获取位置上的棋子id，失败返回0
function whatPiece(theFiled, thePos) {
    if (theFiled.length != 32)
        return 0;
    for (let i = 0; i != 31; i += 1) {
        if (pic2pos(theFiled[i]) == thePos)
            return pic2id(theFiled[i]);
    }
    return 0;
}

//获取棋子指针
function getPtrById(theFiled, theId) {
    if (theFiled.length != 32 || theId < 1 || theId > 32)
        return null;
    //遍历比较
    const tmp1 = theId * 100;
    const tmp2 = tmp1 + 99;
    for (let i = 0; i <= 31; i += 1) {
        if (tmp1 <= theFiled[i] && tmp2 >= theFiled[i])//找到
            return i;
    }
    return null;
}

function getPtrByPos(theFiled, thePos) {
    if (theFiled.length != 32 || thePos < 0 || thePos > 90)
        return null;
    for (let i = 0; i <= 31; i += 1) {
        if (pic2pos(theFiled[i]) == thePos)
            return i;
    }
    return null;
}

//移动棋子，如果目标位置有棋子会直接吃掉，移动之后会渲染新的
function moveById(theFiled, theId, thePos) {
    if (theId < 1 || theId > 32 ||
        thePos < 0 || thePos > 90 ||
        theFiled.length != 32)//参数错误
        return false;
    if (isPiece(theFiled, thePos))//目标位置有棋子
    {
        let tmpPtr = getPtrByPos(theFiled, thePos);
        theFiled[tmpPtr] = pic2id(theFiled[tmpPtr]) * 100 + 90;//隐藏
    }
    theFiled[getPtrById(theFiled, theId)] = Math.floor(theId) * 100 + thePos;//修改位置
    if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 10 / 13)//竖屏
        rende(theFiled);
    else if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 3 / 2)
        rende2(theFiled);
    else
        rende3(theFiled);
    return true;
}

//因为不能修改css文件的内容，要进行媒体查询式的修改可能比较困难和占用资源
let status_t = true;

function test1() {
    //读取窗口分辨率
    let vh = document.documentElement.clientHeight / 100;
    let vw = document.documentElement.clientWidth / 100;
    if (status_t) {
        status_t = false;
        if (vw / vh <= 10 / 13) {//竖屏
            document.getElementById('p17').style.paddingTop = '14.5vw';
        }
        else if (vw / vh < 3 / 2) {//方屏
            document.getElementById('p17').style.paddingLeft = '50.7vh';
        }
        else {//宽屏
            document.getElementById('p17').style.paddingLeft = 'calc(50vw - 50vh * 896 / 1024 + 48.8vh)'
        }
    }
    else {
        status_t = true;
        if (vw / vh <= 10 / 13) {//竖屏
            document.getElementById('p17').style.paddingTop = '4.5vw';
        }
        else if (vw / vh < 3 / 2) {//方屏
            document.getElementById('p17').style.paddingLeft = '0.5vh';
        }
        else {//宽屏
            document.getElementById('p17').style.paddingLeft = 'calc(50vw - 50vh * 896 / 1024 - 1.6vh)'
        }
    }
}

//dom显示时间
let tmp = 0;
let curTime = 12;//12s
function printTime() {
    if (curTime == 10)//切换读秒方式
    {
        clearInterval(tmp);
        tmp = setInterval(printTime, 100);
        curTime -= 0.1;
    }
    //document.getElementById('content').innerHTML = curTime.toString();
    if (curTime >= 10) {
        curTime -= 1;
        document.getElementById('content').innerHTML = curTime.toString();
    }
    else {
        curTime -= 0.1;
        document.getElementById('content').innerHTML = curTime.toFixed(1);
        if (curTime < 0) {
            clearInterval(tmp);
            document.getElementById('content').innerHTML = 'You Louse!';
            return;
        }
    }
}

//生成随机整数
function rand(m, n) {
    return m + Math.floor((n - m + 1) * Math.random());
}


let status_f = false;

//闪烁
function flash() {
    if (status_f)
        document.getElementById(flashElementId).style.visibility = 'hidden';
    else
        document.getElementById(flashElementId).style.visibility = 'visible';
    status_f = !status_f;
}

let flashElementId = '';//闪烁的棋子的id

let flashID = 0;//存储setInterval返回值用于取消闪烁

//闪烁控制函数
function flashCTR(theId) {
    if (flashID == 0)//开启闪烁
    {
        flashElementId = theId;
        document.getElementById(theId).style.visibility = 'hidden';//先隐藏
        status_f = false;
        flashID = setInterval(flash, 400);
    }
    else {
        clearInterval(flashID);
        document.getElementById(theId).style.visibility = 'visible';
        flashID = 0;
    }
}

let status_c = true;//点击状态
let pId;//点击的棋子的id

//点击处理函数
function clickBtn(pos) {
    console.log(pos);
    document.getElementById('content').innerText = '您按下的位置是 ' + pos;
    //if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 10 / 13) {//竖屏
    let pPos = pos;
    if (status_c) {//第一次点击
        if (isPiece(ofiled3, pPos)) {//点到棋子上，把框框移过去
            pId = getIdByPos(ofiled3, pPos);
            flashCTR('p' + pId);
            if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 10 / 13) {//竖屏
                document.getElementById('f1').style.paddingTop = yrange[pos2y(pPos)] + 'vw';
                document.getElementById('f1').style.paddingLeft = xrange[pos2x(pPos)] + 'vw';
            }
            else if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 3 / 2) {//方屏
                document.getElementById('f1').style.paddingTop = yrange2[pos2y(pPos)] + 'vh';
                document.getElementById('f1').style.paddingLeft = xrange2[pos2x(pPos)] + 'vh';
            }
            else {//宽屏
                document.getElementById('f1').style.paddingTop = yrange2[pos2y(pPos)] + 'vh';
                document.getElementById('f1').style.paddingLeft = 'calc(50vw - 50vh * 900 / 1000 + ' + xrange2[pos2x(pPos)] + 'vh)';
            }
            status_c = false;
        }
    }
    else {//第二次的点击
        if (pPos != 90) {//没有点空
            status_c = true;
            moveById(ofiled3, pId, pPos);
            flashCTR('p' + pId);
        }
    }
    //}
}

$(document).ready(function () {
    if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 10 / 13)//竖屏
    {
        btnInit1();//初始化按钮
        rende(ofiled3);//初始化棋盘
    }
    else if (document.documentElement.clientWidth / document.documentElement.clientHeight <= 3 / 2)//方屏
    {
        btnInit2();
        rende2(ofiled3);//初始化棋盘
    }
    else//宽屏
    {
        btnInit3();
        rende3(ofiled3);//初始化棋盘
    }
})