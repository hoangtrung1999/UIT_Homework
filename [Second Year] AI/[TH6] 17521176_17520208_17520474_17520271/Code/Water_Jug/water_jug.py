def water_jug(x, y, res):
    if (x < res and y < res) or x == y or x < 1 or y  < 1:
        return False
    if x == res:
        print_jug(x, y, [(x, 0)])
        return
    if y == res:
        print_jug(x, y, [(0, y)])
        return
    route1, step1 = pour(x, y, res)
    route2, step2 = pour(y, x, res, 1)
    if step1 < step2:
        print_jug(x, y, route1)
    else:
        print_jug(x, y, route2)

def pour(x, y, res, reverse = 0):
    step = 0
    route = []
    vy = vx = 0
    if reverse == 0:
        while 1:
            if vy == res:
                break
            if vy == 0:
                vy = y
                route.append((vx, vy))
                step += 1
            if vx == x:
                vx = 0
                route.append((vx, vy))
                step += 1
            if vy > 0 and vx < x:
                k = min(vy, x - vx)
                vx += k
                vy -= k
            route.append((vx, vy))
            step += 1
    else:
        while 1:
            if vy == res:
                break
            if vy == 0:
                vy = y
                route.append((vy, vx))
                step += 1
            if vx == x:
                vx = 0
                route.append((vy, vx))
                step += 1
            if vy > 0 and vx < x:
                k = min(vy, x - vx)
                vx += k
                vy -= k
            route.append((vy, vx))
            step += 1
    return route, step

def print_jug(x, y, route):
    m = max(x, y)
    for i in range(len(route)):
        print(route[i])
        for j in range(m):
            if j >= m - x:
                print('|', end = '')
                if j >= m - route[i][0]:
                    print('████', end = '')
                else:
                    print('    ', end = '')
                print('|\t', end = '')
            else:
                print('     \t', end = '')
            if j >= m - y:
                print('|', end = '')
                if j >= m - route[i][1]:
                    print('████', end = '')
                else:
                    print('    ', end = '')
                print('|', end = '')
            
            print()        
        print(' ¯¯¯¯ \t ¯¯¯¯ ')
    print("Done")

water_jug(0, 5, 1)




