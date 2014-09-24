<?php

class Solutions 
{
  public function Problem1()
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
}
