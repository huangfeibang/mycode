var board_width,board_height;
var distancew, distanceh;
var board_left,board_top;
function f() {
    var w=window.innerWidth
        || document.documentElement.clientWidth
        || document.body.clientWidth;

    var h=window.innerHeight
        || document.documentElement.clientHeight
        || document.body.clientHeight;

    var x=document.getElementById("demo");
    x.innerHTML="浏览器的内部窗口宽度：" + w + "，高度：" + h + "。"

}
function getposition(event){
    x=event.clientX
    y=event.clientY
    //alert("鼠标的x坐标："+ x +"鼠标的y坐标：" + y);
    if(x >= board_left && x <= board_left + board_width && y>=board_top && y<=board_top+board_height)
    {
        var rows, columns;
        columns  = Math.floor((x-board_left)/distancew);
        rows = Math.floor((y-board_top)/distancew);
        //alert("鼠标行为："+ rows +",鼠标的列为：" + columns);
        return{
            row:rows,
            column:columns
        };
        //alert("鼠标行为："+ position.rows +"鼠标的列为：" + position.columns);
    }
}
window.onload = Initialization;
window.onresize = adjuest;
//window.onload = Initialization_layout;

var map = new Array();
for(var i = 0;i<10;i++)
{
    map[i] = new Array();
    for(var j = 0;j<9;j++)
    {
        map[i][j] = 0;
    }
}

function Initialization()//初始化函数
{
    Initialization_position();
    adjuest();
    show();
    main();
}
function show() {
    body.style.display="block";
}


function adjuest(){//初始化和调整棋盘
    var board = document.getElementById("board");
    var width=window.innerWidth
        || document.documentElement.clientWidth
        || document.body.clientWidth;
    var height=window.innerHeight
        || document.documentElement.clientHeight
        || document.body.clientHeight;
    height = height-11;//消除底边白色，不知道为什么会有
    if(width<height*0.9) {//窄屏幕
        board.style.width = "100%";
        board.style.height=width/0.9+"px";
        board_left = 0;
        board.style.left = board_left;
        board_width = width;
        board_height = width/0.9;
        board_top = (height-width/0.9)/2;
        board.style.top = (height-width/0.9)/2+"px";

        var imformation_opponent = document.getElementById("imformation_opponent");
        imformation_opponent.style.top = 0;
        imformation_opponent.style.left = 0;
        imformation_opponent.style.width = board_width+"px";
        imformation_opponent.style.height = (height-board_height)/2+"px";

        var imformation_self = document.getElementById("imformation_self");
        imformation_self.style.top = (height-board_height)/2+ board_height +10+"px";
        imformation_self.style.left = 0;
        imformation_self.style.width = board_width+"px";
        imformation_self.style.height = (height-board_height)/2-10+"px";
        if(width>=0.6*height)
        {
            opponent_icon.style.width = 0.7*(height-board_height)/2+"px";
            opponent_icon.style.height = opponent_icon.style.width;

            message_opponent.style.fontSize = (height-board_height)/2*0.14+"px";
            step_time.style.fontSize = (height-board_height)/2*0.14+"px";
            left_time.style.fontSize = (height-board_height)/2*0.14+"px";
            invite.style.fontSize = (height-board_height)/2*0.14+"px";
        }
        else
        {
            opponent_icon.style.width = width*0.2+"px";
            opponent_icon.style.height = opponent_icon.style.width;
            message_opponent.style.fontSize = width*0.3*0.14+"px";
            step_time.style.fontSize = width*0.3*0.14+"px";
            left_time.style.fontSize = width*0.3*0.14+"px";
            invite.style.fontSize = width*0.3*0.14+"px";

        }

        //alert(opponent_icon.style.width);
    }
    else if(width==height*0.9)//正方形屏幕
    {

        board.style.width = width+"px";
        board.style.height= height +"px";
        board.style.left = 0;
        board.style.top = 0;
        board_width = width;
        board_height = height;
        board_left = 0;
        board_top = 0;
    }
    else//宽屏幕
    {
        board.style.height = height+"px";
        board.style.width = height*0.9+"px";
        board.style.left = (width-height*0.9)/2+"px";
        board_width = height*0.9;
        board_height = height;
        board.style.top = 0;
        board_top = 0;
        board_left = (width-height*0.9)/2;

    }
    distancew = board_width/9;
    distanceh = board_height/10;

    //
    var txt;
    var chessman;
    b1.style.left = distancew*b1.posx+"px";
    b1.style.top = distanceh*b1.posy+"px";
    for(var i = 2;i<=5;i++)//放置第一排棋子
    {
        txt="b"+i+"_"+1;
        chessman = document.getElementById(txt);
        chessman.style.left = distancew*chessman.posx+"px";
        chessman.style.top = distanceh*chessman.posy+"px";
        txt="b"+i+"_"+2;
        chessman = document.getElementById(txt);
        chessman.style.left = distancew*chessman.posx+"px";
        chessman.style.top = distanceh*chessman.posy+"px";
    }
    b6_1.style.left = distancew*b6_1.posx+"px";
    b6_1.style.top = distanceh*b6_1.posy+"px";
    b6_2.style.left = distancew*b6_2.posx+"px";
    b6_2.style.top = distanceh*b6_2.posy+"px";
    for(var i = 1;i<=5;i++)//初始化卒
    {
        txt = "b7_" + i;
        chessman = document.getElementById(txt);
        chessman.style.left = chessman.posx*distancew+"px";
        chessman.style.top = chessman.posy*distanceh+"px";
    }

    r1.style.left = distancew*r1.posx+"px";
    r1.style.top = distanceh*r1.posy+"px";
    for(var i = 2;i<=5;i++)//放置第一排棋子
    {
        txt="r"+i+"_"+1;
        chessman = document.getElementById(txt);
        chessman.style.left = distancew*chessman.posx+"px";
        chessman.style.top = distanceh*chessman.posy+"px";
        txt="r"+i+"_"+2;
        chessman = document.getElementById(txt);
        chessman.style.left = distancew*chessman.posx+"px";
        chessman.style.top = distanceh*chessman.posy+"px";
    }
    r6_1.style.left = distancew*r6_1.posx+"px";
    r6_1.style.top = distanceh*r6_1.posy+"px";
    r6_2.style.left = distancew*r6_2.posx+"px";
    r6_2.style.top = distanceh*r6_2.posy+"px";
    for(var i = 1;i<=5;i++)//初始化卒
    {
        txt = "r7_" + i;
        chessman = document.getElementById(txt);
        chessman.style.left = chessman.posx*distancew+"px";
        chessman.style.top = chessman.posy*distanceh+"px";
    }


}
function Initialization_position()//初始化棋子位置

{
    var txt;
    var chessman;
    b1.posx = 4;
    b1.posy = 0;
    for(var i = 2;i<=5;i++)//初始化第一排棋子位置
    {
        txt="b"+i+"_"+1;
        chessman = document.getElementById(txt);
        chessman.posx = 5-i;
        chessman.posy = 0;
        txt="b"+i+"_"+2;
        chessman = document.getElementById(txt);
        chessman.posx = i+3;
        chessman.posy = 0;
    }
    b6_1.posx = 1;//初始化炮的位置
    b6_1.posy = 2;
    b6_2.posx = 7;
    b6_2.posy = 2;
    for(var i = 1;i<=5;i++)//初始化卒的位置
    {
        txt = "b7_" + i;
        chessman = document.getElementById(txt);
        chessman.posx = 2*(i-1);
        chessman.posy = 3;
    }
//对方棋子位置
    r1.posx = 4;
    r1.posy = 9;
    for(var i = 2;i<=5;i++)//初始化第一排棋子位置
    {
        txt="r"+i+"_"+1;
        chessman = document.getElementById(txt);
        chessman.posx = 5-i;
        chessman.posy = 9;
        txt="r"+i+"_"+2;
        chessman = document.getElementById(txt);
        chessman.posx = i+3;
        chessman.posy = 9;
    }
    r6_1.posx = 1;//初始化炮
    r6_1.posy = 7;
    r6_2.posx = 7;
    r6_2.posy = 7;
    for(var i = 1;i<=5;i++)//初始化卒
    {
        txt = "r7_" + i;
        chessman = document.getElementById(txt);
        chessman.posx = 2*(i-1);
        chessman.posy = 6;
    }
//己方棋子位置
}
var f = 0;
var ID1;
function move(id)
{
    if(f == 0)
    {
        ID1 = id;
        var position1 = getposition(event);
        moveto(frame_green,position1.row,position1.column);
    }
    f++;
    if(f == 2)
    {
        var position1 = getposition(event);
        moveto(ID1,position1.row,position1.column);
        id.parentNode.removeChild(id);
        f = 0;
    }
}
function clickboard() {
    if(f == 1)
    {
        var position1 = getposition(event);
        moveto(ID1,position1.row,position1.column);
        f = 0;
    }
}
function moveto(id, row, column) {
    id.style.top = distanceh*row+"px";
    id.style.left = distancew*column+"px";
}



//以下是逻辑部分
function main() {

    for(var i = 0;i<10;i++)
    {
        map[i] = new Array();
        for(var j = 0;j<9;j++)
        {
            map[i][j] = 0;
        }
    }
    /*for(var i = 0;i<10;i++)
    {
        for(var j = 0;j<9;j++)
        {
            console.log(map[i][j]+"\n");
        }
    }*/
}



