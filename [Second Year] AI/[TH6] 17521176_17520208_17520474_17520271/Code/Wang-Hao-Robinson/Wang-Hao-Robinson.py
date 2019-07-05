'''
A not so efficient implementation of Wang Hao and Robinson algorithm
Only works with operators (and ^), (or v), (not ~) and (=>) to split premises and conclusion
Given an argument, we want to prove it True or False, with:
Argument = (Premises => Conclusion)
Premises and Conclusion is composed by one or many propositions, or simply variables, ie p, q, r
(,) in premises is (and), while in conclusion it is (or)
'''

import itertools


# Cosmetic
def print_tab(tab):
    for i in range(tab):
        print('\t', end='')


# Cosmetic
def print_statement(premises, conclusion, tab):
    n_p = len(premises)
    n_c = len(conclusion)
    print_tab(tab)
    print('Check', end=' ')

    for i in premises:
        if n_p > 1:
            print(i, end=', ')
            n_p -= 1
        else:
            print(i, end=' => ')

    for i in conclusion:
        if n_c > 1:
            print(i, end=', ')
            n_c -= 1
        else:
            print(i)


# Cosmetic
def R_print_statement(premises):
    n_p = len(premises)
    for i in premises:
        if n_p > 1:
            print(i, end=', ')
            n_p -= 1
        else:
            print(i)


# Return negation of a proposition, ie a -> ~a, ~b -> b
def negate(char):
    if '~' in char:
        return char.strip('~')
    else:
        return '~'+char


def WH_normalize(premises, conclusion):
    for i in premises.copy():
        # ~a, ... => b == ... => b, a
        if '~' in i and len(i) == 2:
            conclusion.add(i.strip('~'))
            premises.discard(i)
        # a ^ b => ... == a, b => ...
        elif '^' in i:
            premises.discard(i)
            premises.update(i.split('^'))
    for i in conclusion.copy():
        # b => ~a, ... == b, a => ...
        if '~' in i and len(i) == 2:
            premises.add(i.strip('~'))
            conclusion.discard(i)
        # ... => a v b == ... => a, b
        elif 'v' in i:
            conclusion.discard(i)
            conclusion.update(i.split('v'))


'''
Main idea of Wang Hao is if a proposition is a member in both premises and conclusion, the argument is proved True
In any proposition with more than 2 variables, we will split it into smaller branches and prove each True
If exists a False branch, the argument is proved False, otherwise True
p, q v r => q (1)
split q v r
    p, q => q: True
    p, r => q: False -> (1) False
'''
def WangHao(premises, conclusion, tab=0):
    # Cosmetic
    print_statement(premises, conclusion, tab)
    WH_normalize(premises, conclusion)
    # Indicate depth of recursion
    main_branch = False

    for i in premises:
        if 'v' in i:
            main_branch = True
            branch = premises.copy()
            # Remove multi-variable propositions
            branch.discard(i)
            # For each single variable
            for j in i.split('v'):
                branch_temp = branch.copy()
                # Add back and check
                branch_temp.add(j)
                conclu_temp = conclusion.copy()
                if not WangHao(branch_temp, conclu_temp, tab+1):
                    return False
    # Same for conclusion set
    for i in conclusion:
        if '^' in i:
            main_branch = True
            branch = conclusion.copy()
            branch.discard(i)
            for j in i.split('^'):
                branch_temp = branch.copy()
                branch_temp.add(j)
                prem_temp = premises.copy()
                if not WangHao(prem_temp, branch_temp, tab+1):
                    return False
    # Either it's a single value branch check -> Intersection between premises and conclusion
    # Or all smaller branches have been checked
    if len(premises & conclusion) > 0 or main_branch:
        return True
    # Single value branch fails check
    return False


def R_normalize(premises, conclusion):
    for i in premises.copy():
        # a ^ b => ... == a, b => ...
        if '^' in i:
            premises.discard(i)
            premises.update(i.split('^'))
    for i in conclusion.copy():
        # ... => a v b == ... => a, b
        if 'v' in i:
            conclusion.discard(i)
            conclusion.update(i.split('v'))
    # Bring all propositions in conclusion to premises
    for i in conclusion.copy():
        temp = []
        for j in i.split('^'):
            temp.append(negate(j))
        premises.add('v'.join(temp))


# Find a proposition pair with complementary literals (variable with negation of itself)
# Ie (a, ~a), (a v xxx, ~a v zzz)
def find_pair(statement):
    list_p = set()
    list_pn = set()
    temp = statement.copy()

    for i in statement:
        # Remove proposition in question for no duplicate
        temp.discard(i)
        # Check every variable
        for j in i.split('v'):
            # Check the rest of statement
            for k in temp:
                # Tricky part
                # Suppose we got a, we need to find ~a
                if negate(j) in k:
                    # But if we got ~a, a is both in a and ~a
                    if '~' not in j or j not in k:
                        list_pn.add(k)
                        # Added in negation list, skip
                        continue
                # We also find other proposition with a in it
                if j in k:
                    list_p.add(k)
            # A complementary pair is found
            if len(list_pn) != 0:
                # Add the original location
                list_p.add(i)
                # Return 2 lists and key of the pair
                return list_p, list_pn, j
            else:
                # Rerun for other proposition
                list_p.clear()

    return list_p, list_pn, None


'''
In Robinson, we bring all conclusion to premises and prove
Knowing p ^ ~p yields True, the idea is to pair all complementary literals and use the rule of elimination
p ^ (~p v q) = q
In the end, if all is eliminated, the argument is True
Otherwise, False
'''
def Robinson(premises, conclusion):
    # Cosmetic
    print_statement(premises, conclusion, 0)
    print('Check', end=' ')
    R_normalize(premises, conclusion)
    R_print_statement(premises)

    p, pn, key = find_pair(premises)
    # key = None, out loop
    while key:
        # Split to variables
        t_p = [i.split('v') for i in p]
        t_pn = [i.split('v') for i in pn]
        # Remove key
        for i in t_p:
            i.remove(key)
        for i in t_pn:
            i.remove(negate(key))
        # Then join again
        # len > 0 is to get rid of single proposition (which is also key), which this code return ''
        t_p = ['v'.join(i) for i in t_p if len(i) > 0]
        t_pn = ['v'.join(i) for i in t_pn if len(i) > 0]

        # Remove propositions with key
        premises.difference_update(p)
        premises.difference_update(pn)

        # Rule of elimination
        # Tricky part
        # [p ^ (~p v q) = q] or [p, ~p v q = q]
        # p v q, ~p v r = q v r
        # a v b, a v c, ~a v d, ~a v e = b v d, b v e, c v d, c v e
        # Try to prove it
        if len(t_p) == 0:
            premises.update(t_pn)
        elif len(t_pn) == 0:
            premises.update(t_p)
        else:
            for i in itertools.product(t_p, t_pn):
                premises.add('v'.join(set(i)))

        print('Eliminate '+key+', '+negate(key))
        R_print_statement(premises)

        # Find it again
        p, pn, key = find_pair(premises)

    # Eliminated all
    if len(premises) == 0:
        return True
    return False


def process(input):
    premises, conclusion = input.split('=>')
    premises = premises.split(',')
    conclusion = conclusion.split(',')

    return set(premises), set(conclusion)

if __name__ == '__main__':
    print('not ~\tand ^\tor v\tsplit =>')
    print('No spacing')
    input = input()
    p, c = process(input)
    print('Wang Hao:')
    print(WangHao(p, c))
    print('Robinson:')
    print(Robinson(p, c))