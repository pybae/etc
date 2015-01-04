#!/usr/bin/env ruby
# encoding: utf-8

sum = 0
a, b = 1, 1
while b <= 4000000
  if b.even?
    sum += b
  end
  a, b = b, a + b
end

puts sum
