#!/usr/bin/env ruby
# encoding: utf-8

num = 600851475143
factor = 2

while num != 1
  if num % factor == 0
    while num % factor == 0
      num /= factor
    end
  else
    factor += 1
  end
end

puts factor
