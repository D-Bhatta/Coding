""" Palin the next palindrome """

n = int(input())

def generate_palindrome(input_string):
    # check if all digits are 9s
    def all_9s():
        temp = set(input_string)
        if temp == {'9'}:
            return True
        else:
            return False
    # if all 9s, return num + 2 here:
    # example-> 999 +2 = 1001
    if(all_9s()):
        output_string = "1" + "0"*(len(input_string)-1) + "1"
        return  output_string
    # for other cases
    def generate_palindrome_util(input_string):
        size = len(input_string)
        # middle elements 
        mid = size//2
        # check if lesft is smaller
        left_smaller = False
        # end of left side
        i = mid - 1
        # beginning of right side
        if size % 2 == 0:
            j =  mid
        else:
            j = mid+1
        # ignore the same middle digits
        while((i >= 0) and (input_string[i] == input_string[j])):
            i = i-1
            j = j+1
        # check if middle digits need to be incremented or not or
        # copying left side is not sufficient
        if( (i < 0) or (input_string[i] < input_string[j])):
            left_smaller = True
        
        # mirror left side on right side
        while i >= 0 :
            input_string = input_string[:j] + input_string[i] + input_string[j+1:]
            j = j + 1
            i = i - 1
        
        # handle the case where middle digits must be incremented
        if left_smaller == True:
            # carry store the increment to the digits
            carry = 1
            # position i to the end of the left side
            i = mid - 1
            # if there are odd digits then increment the middle digits
            if size %2 == 1:
                # take the num value of the character at mid
                temp = int(input_string[mid])
                # increment the num value by carry
                temp += carry
                # store the MSB digit of the num value in carry
                carry = temp//10
                #  store the LSB digit of the num value in temp
                temp %= 10
                # store back num value as string
                input_string = input_string[:mid] + str(temp) + input_string[mid+1:]
                #  position j at the beginning of the right side
                j = mid + 1
            else:
                #  position j at the beginning of the right side
                j = mid
            """add 1 to the right most digit of the left side,
            \npropagate the carry toward the MSb digit and simultenously 
            \nmirror the left side to the right side  """
            while i >= 0:
                # take the value of the character at i
                temp = int(input_string[i])
                # add carry num value, initially incrementing it by 1
                temp = temp + carry
                # store MSBs except for units digit in carry
                carry = temp // 10
                # store units digit in temp
                temp = temp % 10
                # store temp value at input_string[i] as string
                input_string = input_string[:i] + str(temp) + input_string[i+1:]
                # mirror left side to right side
                input_string = input_string[:j] + input_string[i] + input_string[j+1:]                
                j = j + 1
                i = i - 1
        return input_string
    return generate_palindrome_util(input_string)


for i in range(n):
    input_string = input()
    print(generate_palindrome(input_string), end='\n')

""" Time limit exceeded on SPOJ but cna't find why """

