#!/usr/bin/env ruby
# encoding: utf-8

max = 0

def isPalindrome(string)
  return string == string.reverse
end

for i in 100..999
  for j in 100..999
    if isPalindrome((i*j).to_s) and i*j > max
      max = i*j
    end
  end
end

puts max
