import copy
import bisect
max_win=0
max_win_dice=None

def cal2(k, num, a, dice, ret):
    if k==len(a):
        ret.append(num)
        return
    for i in range(6):
        cal2(k+1,num+dice[a[k]][i],a,dice,ret)
        
def cal(a,b,dice):
    n=len(dice)/2
    a_num_list=[]
    cal2(0,0,a,dice,a_num_list)
    b_num_list=[]
    cal2(0,0,b,dice,b_num_list)
    
    b_num_list.sort()
    cnt=0
    for i in a_num_list:
        cnt+=bisect.bisect_left(b_num_list,i)
    return cnt

def select(k, dice, choice):
    global max_win
    global max_win_dice
    if len(choice)==len(dice)/2:
        my_dice=choice
        op_dice=[d for d in range(0,len(dice)) if d not in choice]
        win=cal(my_dice, op_dice,dice)
        if win>max_win:
            max_win=win
            max_win_dice=copy.deepcopy(my_dice)
        return
    elif k==len(dice):
        return

    choice.append(k)
    select(k+1, dice, choice)
    choice.pop()
    select(k+1, dice, choice)

def solution(dice):
    select(0, dice, [])
    return [x+1 for x in sorted(max_win_dice)]