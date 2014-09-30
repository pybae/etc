<?php

class Solutions 
{
    private function prime_values($limit) {
        // Sieve of erathosthenes implementation
        $range = range(2, $limit);
        $primes = array_combine($range, $range);
        $num = 2;

        while ($num*$num < $limit) {
            for ($i = 2*$num; $i <= $limit; $i += $num) {
                unset($primes[$i]);
            }
            $num = next($primes);
        }

        reset($primes);
        return $primes;
    }

    private function prime_factors($limit) {
        $factors = array();
        $primes  = array();
        $num = 2;

        for ($i = 2; $i < $limit+1; $i++) {
            if (!in_array($i, $factors) and $limit % $i === 0) {
                array_push($primes, $i);
          
                // $factors = $factors + range($i*$i, $limit, $i);
                // This doesn't work since it merges by key values favoring the left hand side;
                // In other words
                // {1, 2} + {3, 4, 5} = {1, 2, 4}

                // The following is proper merging
                $factors = array_unique(array_merge($factors, range($i*$i, $limit, $i)));
            }
        }

        return $primes;
    }

    function Problem1()
    {
        $sum = 0;
        $n = 1000;
        for ($i = 0; $i < $n; $i++) {
            if ($i % 3 === 0) {
                $sum += $i;
            }
            else if ($i % 5 === 0) {
                $sum += $i;
            }
        }

        return $sum;
    }

    function Problem2() 
    {
        $sum = 0;
        $a = 0;
        $b = 1;
        while ($b < 4000000) {
            if ($b % 2 == 0) {
                $sum += $b;
            }
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        return $sum;
    }

    function Problem3()
    {
        $primes = $this->prime_values(100000);
        $n = 600851475143;
        $i = 0;
    
        while ($n > 1) {
            if ($n % current($primes) === 0) {
                $n /= current($primes);
            }
            else {
                next($primes);
            }
        }
        return current($primes);
    }

    function Problem4()
    {
        $max = 0;
        for ($i = 999; $i > 100; $i--) {
            for ($j = 999; $j > 100; $j--) {
                if ($i*$j < $max) {
                    break;
                }
                if (strval($i*$j) === strrev(strval($i*$j)) and $i*$j > $max) {
                    $max = $i*$j;
                }
            }
        }
        return $max;
    }

    function Problem5()
    {
        $n = 20;
        $max_prime_factors = array();
        $max_prime_powers  = array();

        for ($i = 1; $i <= $n; $i++) {
            $factors = $this->prime_factors($i);
            for ($j = 0; $j < count($factors); $j++) {
                $factor = $factors[$j];
                $power = 0;

                $temp = $i;
                while ($temp % $factor === 0) {
                    $power++;
                    $temp /= $factor;
                }

                if (in_array($factor, $max_prime_factors)) {
                    $index = array_search($factor, $max_prime_factors);
                    if ($max_prime_powers[$index] < $power) {
                        $max_prime_powers[$index] = $power;
                    }
                }
                else {
                    array_push($max_prime_factors, $factor);
                    array_push($max_prime_powers, $power);
                }
            }
        }

        $result = array_map(function ($a, $b) {
            return pow($a,$b);
        }, $max_prime_factors, $max_prime_powers);

        return array_product($result);
    }

    function Problem6()
    {
        $sum = 0;
        $n = 100;
        for ($i = 0; $i <= $n; $i++) {
            for ($j = $i+1; $j <= $n; $j++) {
                $sum += $i*$j;
            }
        }
        return 2*$sum;
    }

    function Problem7()
    {
        $primes = $this->prime_values(200000);
        
        for ($i = 0; $i < 10000; $i++) {
            next($primes);
        }

        return current($primes);
    }

    function Problem8()
    {
        $number = "
7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450V
";
        $number = trim($number);
        $current = 0;
        $max_v = 0;

        for ($i = 0; $i < strlen($number)-12; $i++) {
            if ($current === 0) {
                $current = 1;
                for ($j = $i; $j < min(strlen($number), $i + 13); $j++) {
                    if ((int) $number[$j] === 0) {
                        $current = 0;
                        $i += $j - $i;
                        continue;
                    }
                    else {
                        $current *= (int) $number[$j];
                    }
                }
                $max_v = max($current, $max_v);
            }
            else {
                if ((int) $number[$i+12] === 0) {
                    $current = 0;
                }
                else {
                    $current *= (int) $number[$i+12];
                    $current /= (int) $number[$i-1];
                    $max_v = max($current, $max_v);
                }
            }
        }

        return $max_v;
    }

    function Problem9()
    {
        return 0;
    }
}
