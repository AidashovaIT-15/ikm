                АЙДАШОВА И. ИТ-15 Вариант 4
Абстрактная вычислительная машина имеет один регистр и шесть 

инструкций:

LD A Помещает операнд А в регистр

ST A Помещает содержимое регистра в переменную с именем А

AD A Прибавляет значение А к регистру. Результат остается в 

регистре.

SB A Вычитает значение А из регистра. Результат остается в регистре.

ML A Умножает содержимое регистра на значение переменной с 

именем A. Результат остается в регистре. 

DV A Делит содержимое регистра на значение А. 

Результат остается в регистре.

Дано выражение в постфиксной форме, состоящее из однобуквенных 

операндов и операций «+», «–», «*», «/». Написать программу вывода 

инструкций вычислительной машины, необходимых для вычисления 

выражения. Результат вычисления должен оставаться в регистре, 

разрешается использовать обозначения Tn для временных переменных.

Пример: для выражения ABC*+DE-/ перечень инструкций имеет вид

LD B

ML C

ST T1

LD A

AD T1

ST T1

LD D

SB E

ST T2

LD T1

DV T2

Замечание: Постфиксной формой записи выражения a b называется запись, в 

которой знак операции размещен за операндами a b. 

Примеры: 

a - b → a b –

a * b + c → a b * c + 

a * (b + c) → a b c + * 

a + b / c / d * e → a b c / d / e * +
