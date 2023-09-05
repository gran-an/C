using System;

class Program {
    static void Main() {
        // decimal(bits[0], bits[1], bits[2], sign, exp) Для справки

        // Сумма
        decimal add_1 = new decimal(10, 0, 0, false, 0);
        decimal add_2 = new decimal(10, 0, 0, false, 0);
        PrintDecimalBits("Cумма", add_1 + add_2);

        // Вычитание
        decimal sub_1 = new decimal(10, 0, 0, false, 0);
        decimal sub_2 = new decimal(10, 0, 0, false, 0);
        PrintDecimalBits("Вычитание", sub_1 - sub_2);

        // Умножение
        decimal mul_1 = new decimal(10, 0, 0, false, 0);
        decimal mul_2 = new decimal(10, 0, 0, false, 0);
        PrintDecimalBits("Умножение", mul_1 * mul_2);

        // Деление
        decimal div_1 = new decimal(0, 1, 0, false, 0);
        decimal div_2 = new decimal(10, 0, 0, false, 0);
        PrintDecimalBits("Деление", div_1 / div_2);

        // Из децимала в инт
        decimal dec_to_int = new decimal(123, 0, 0, false, 1);
        Console.WriteLine("Из децимал в инт: " + decimal.ToInt32(dec_to_int));

        // Из децимала в флоат
        decimal decimal_to_float = new decimal(0, 0, 1, false, 0);
        Console.WriteLine("Из децимал в флоат: " + (float)decimal.ToDouble(decimal_to_float)+ "\n");

        // Из инт в децимал
        int int_to_dec = 100;
        PrintDecimalBits("Из инт в децимал", new decimal(int_to_dec));

        // Из флоат в децимал
        float float_to_dec = 256.64f;
        PrintDecimalBits("Из флоат в децимал", new decimal(float_to_dec));

        // floor - Округляет до ближайшего целого числа в сторону отрицательной бесконечности
        decimal floor = new decimal(954, 0, 0, false, 2);
        PrintDecimalBits("floor", decimal.Floor(floor));

        // round - Округляет до ближайшего целого числа
        decimal round = new decimal(954, 0, 0, false, 2);
        PrintDecimalBits("round", decimal.Round(round));

        // truncate - Возвращает целые цифры; любые дробные цифры отбрасываются, включая конечные нули
        decimal truncate = new decimal(123, 123, 0, false, 1);
        PrintDecimalBits("truncate", decimal.Truncate(truncate));

        // negate - Возвращает результат умножения указанного на -1
        decimal negate = new decimal(954, 0, 0, false, 2);
        PrintDecimalBits("negate", decimal.Negate(negate));

        // Равно
        decimal equal_1 = new decimal(10, 0, 0, false, 0);
        decimal equal_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Равно: {equal_1 == equal_2}");

        // Не равно
        decimal not_equal_1 = new decimal(10, 0, 0, false, 0);
        decimal not_equal_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Не равно: {not_equal_1 != not_equal_2}");

        // Больше
        decimal greater_1 = new decimal(10, 0, 0, false, 0);
        decimal greater_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Больше: {greater_1 > greater_2}");

        // Больше или равно
        decimal greater_or_equal_1 = new decimal(10, 0, 0, false, 0);
        decimal greater_or_equal_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Больше или равно: {greater_or_equal_1 >= greater_or_equal_2}");

        // Меньше
        decimal less_1 = new decimal(10, 0, 0, false, 0);
        decimal less_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Меньше: {less_1 < less_2}");

        // Меньше или равно
        decimal less_or_equal_1 = new decimal(10, 0, 0, false, 0);
        decimal less_or_equal_2 = new decimal(10, 0, 0, false, 0);
        Console.WriteLine($"Меньше или равно: {less_or_equal_1 <= less_or_equal_2}");
    }

    static void PrintDecimalBits(string text, decimal value) {
        int[] bits = decimal.GetBits(value);
        Console.WriteLine(text);
        for (int i = 0; i < bits.Length; i++) {
            // Console.WriteLine($"bits[{i}]: {(uint)bits[i]} (0x{bits[i].ToString("X8")})"); // в 16-ке
            Console.WriteLine($"bits[{i}]: {(uint)bits[i]}"); // в 10-ке
        }

        Console.WriteLine();
    }
}
