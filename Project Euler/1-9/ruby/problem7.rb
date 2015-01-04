#!/usr/bin/env ruby
# encoding: utf-8

def isPrime(n)
  case
  when n == 1
    return false
  when n < 4
    return true
  when n % 2 == 0
    return false
  when n < 9
    return true
  when n % 3 == 0
    return false
  else
    r = Math.sqrt(n).floor
    f = 5
    while f <= r
      if n % f == 0
        return false
      elsif n % (f + 2) == 0
        return false
      else
        f += 6
      end
    end
  end
  return true
end

num = 10001
count = 1
candidate = 1
while count != num
  candidate += 2
  if isPrime(candidate)
    count += 1
  end
end

puts candidate
