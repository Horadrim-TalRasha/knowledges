#!/usr/bin/python

def trim(target_str):
    if len(target_str) == 0:
        return ""

    lower_bound = 0
    upper_bound = len(target_str)
    for i in target_str:
        if i == ' ':
            lower_bound = lower_bound + 1
        else:
            break

    for j in reversed(target_str):
        if j == ' ':
            upper_bound = upper_bound - 1
        else:
            break

    return target_str[lower_bound:upper_bound]

if __name__ == "__main__":
    trimed_str = trim("  ")
    print len(trimed_str)
