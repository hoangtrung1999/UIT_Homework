//1.31
import numpy as np
def check(coast):
    if (coast[0] == 0 or coast[0] >= coast[1]) and 0 <= coast[0] < 4 and 0 <= coast[1] < 4:
        return True
    return False

def evaluate(left):
    return left[0]*2 + left[1]
    
def output(left, state, right, boat):
    if state:
        print(left, ' --', boat, '-> ', right, sep = '')
    else:
        print(left, ' <-', boat, '-- ', right, sep = '')
        
def miss_cann(left, state, right, last_boat):
    boat = np.array([0, 1])
    cost = 10
    if state == True:
        temp = np.array([0, 1])
        if check(left - temp) and cost > evaluate(left - temp) and check(right + temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left - temp)
        temp = np.array([1, 0])
        if check(left - temp) and cost > evaluate(left - temp) and check(right + temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left - temp)
        temp = np.array([0, 2])
        if check(left - temp) and cost > evaluate(left - temp) and check(right + temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left - temp)
        temp = np.array([2, 0])
        if check(left - temp) and cost > evaluate(left - temp) and check(right + temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left - temp)
        temp = np.array([1, 1])
        if check(left - temp) and cost > evaluate(left - temp) and check(right + temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left - temp)
        left = left - boat
        output(left, state, right, boat)
        right = right + boat
    else:
        temp = np.array([0, 1])
        if check(left + temp) and cost > evaluate(left + temp) and check(right - temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left + temp)
        temp = np.array([1, 0])
        if check(left + temp) and cost > evaluate(left + temp) and check(right - temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left + temp)
        temp = np.array([0, 2])
        if check(left + temp) and cost > evaluate(left + temp) and check(right - temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left + temp)
        temp = np.array([2, 0])
        if check(left + temp) and cost > evaluate(left + temp) and check(right - temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left + temp)
        temp = np.array([1, 1])
        if check(left + temp) and cost > evaluate(left + temp) and check(right - temp) and not np.array_equal(temp, last_boat):
            boat = np.copy(temp)
            cost = evaluate(left + temp)
        right = right - boat
        output(left, state, right, boat)
        left = left + boat
    return left, not state, right, boat

left = np.array([3, 3])
state = True
right = np.array([0, 0])
last_boat = np.array([0, 0])
timeout = 1
while(np.sum(left) != 0):
    left, state, right, last_boat = miss_cann(left, state, right, last_boat)
    timeout += 1
    if timeout > 100:
        break
if timeout > 100:
    print('Time out-ed')