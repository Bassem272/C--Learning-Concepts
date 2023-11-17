In the provided code snippet, various declarations and definitions involving constants, constexpr, and const are present. Let's break down each part:

1. **`const int dmv = 17;`**
   - `dmv` is a named constant.
   - The value of `dmv` cannot be changed; it is initialized at compile time and remains constant during program execution.

2. **`int var = 17;`**
   - `var` is not a constant; it is a regular variable.
   - The value of `var` can be changed during the program execution.

3. **`constexpr double max1 = 1.4 * square(dmv);`**
   - `max1` is a constexpr variable.
   - The expression `1.4 * square(dmv)` is evaluated at compile time because `dmv` is a constant expression.

4. **`constexpr double max2 = 1.4 * square(var);`**
   - Error: `var` is not a constant expression.
   - `max2` cannot be evaluated at compile time because `var` is not a constexpr variable.

5. **`const double max3 = 1.4 * square(var);`**
   - `max3` is a regular constant.
   - The expression `1.4 * square(var)` is evaluated at run time because `var` is not a constexpr variable.

6. **`double sum(const vector<double>&);`**
   - `sum` is a function taking a constant reference to a vector of doubles.
   - The function `sum` promises not to modify its argument.

7. **`vector<double> v {1.2, 3.4, 4.5};`**
   - `v` is not a constant; it is a regular vector.

8. **`const double s1 = sum(v);`**
   - `s1` is a regular constant.
   - The function `sum` is called with vector `v`, and the result is assigned to `s1`. The evaluation happens at run time.

9. **`constexpr double s2 = sum(v);`**
   - Error: `sum(v)` is not a constant expression.
   - `s2` cannot be evaluated at compile time because the argument `v` is not a constexpr variable.

**Summary:**
- `const` is used to declare constants that can be evaluated at run time.
- `constexpr` is used for constants that must be evaluated at compile time. The expression involved must be computable during compilation.
- Regular constants (declared with `const`) can be evaluated at run time.
- `constexpr` variables and expressions must be evaluated at compile time and are subject to stricter rules.