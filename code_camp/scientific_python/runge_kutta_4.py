def rk4(f, t0, y0, tf, h):
    """
    Fourth-order Runge-Kutta method for solving ordinary differential equations.

    Parameters:
        f: function
            The function defining the ordinary differential equation dy/dt = f(t, y).
        t0: float
            Initial time.
        y0: float
            Initial value of the dependent variable.
        tf: float
            Final time.
        h: float
            Step size.

    Returns:
        t_values: list
            List of time values.
        y_values: list
            List of corresponding values of the dependent variable.
    """
    t = t0
    y = y0
    t_values = [t0]
    y_values = [y0]

    while t < tf:
        k1 = h * f(t, y)
        k2 = h * f(t + 0.5 * h, y + 0.5 * k1)
        k3 = h * f(t + 0.5 * h, y + 0.5 * k2)
        k4 = h * f(t + h, y + k3)

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0
        t += h

        t_values.append(t)
        y_values.append(y)

    return t_values, y_values


def my_ode(t, y):
    return -0.5 * y + 3 * t  # Example differential equation: dy/dt = -0.5 * y + 3 * t


t0 = 0.0  # Initial time
y0 = 1.0  # Initial value of y
tf = 5.0  # Final time
h = 0.1   # Step size

t_values, y_values = rk4(my_ode, t0, y0, tf, h)

# Print the results
for t, y in zip(t_values, y_values):
    print(f"t = {t}, y = {y}")