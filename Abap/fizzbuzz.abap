
*&---------------------------------------------------------------------*
*& Report FIZZBUZZ_HACKTOBERFEST
*&---------------------------------------------------------------------*
*&
*&---------------------------------------------------------------------*
report fizzbuzz_hacktoberfest.

parameters: fizzbuzz type i.
data count type i value 1.
data is_multiple_by_three type i.
data is_multiple_by_five type i.

if fizzbuzz < 1 or fizzbuzz > 100.
  write / 'imput out of range (1-100)'.
else.
  do fizzbuzz times.
    is_multiple_by_three = sy-index mod 3.
    is_multiple_by_five = sy-index mod 5.

    if is_multiple_by_three = 0 and is_multiple_by_five = 0.
      write / 'fizzbuzz'.
      continue.
    elseif is_multiple_by_three = 0.
      write / 'fizz'.
    elseif is_multiple_by_five = 0.
      write / 'buzz'.
      continue.
    else.
      write / sy-index.
    endif.
  enddo.
endif.