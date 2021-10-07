import requests
import tkinter as tk
from tkinter import *

# ================================================== WINDOW ============================================================
class Window:
    def __init__(self):
        # INITIAL STRING VALUES == NULL

        self.from_value = ""
        self.currency_from = ""
        self.currency_to = ""

        # ======= ROOT
        root = tk.Tk()

        # ============================================== WINDOW SIZE (MAX & MIN) ==============================================
        root.geometry("370x200+0+0")
        root.minsize(370, 200)
        root.maxsize(370, 200)

        # =================================== Esc & ENTER BUTTON BIND
        root.bind("<Escape>", lambda x: root.destroy())
        root.bind("<Return>", lambda event=None: submit_button.invoke())

        # ================================================== TITLE =============================================================
        root.title("Currency Converter")

        # ======= VARIABLE details
        from_value_var = tk.StringVar()
        to_value_var = tk.StringVar()
        currency_from_var = tk.StringVar()
        currency_to_var = tk.StringVar()

        # ======= SUBMIT FUNCTION
        def submit():
            from_value = str(from_value_var.get())
            currency_from = str(currency_from_var.get())
            currency_to = str(currency_to_var.get())
            if from_value == "":
                error_window = Toplevel(root)
                # Geometry of TopLevel
                error_window.geometry("200x200+370+0")
                error_window.minsize(200, 100)
                error_window.maxsize(200, 100)
                # A Label widget to show in toplevel(Pack)
                Label(
                    error_window,
                    text="⚠️ *From field is empty",
                    font=("Arial", 12, "bold"),
                    fg="Red",
                    padx=30,
                    pady=90,
                ).pack()
            else:
                # ======= API
                url = "https://currency-exchange.p.rapidapi.com/exchange"

                querystring = {
                    "from": str(currency_from),
                    "to": str(currency_to),
                    "q": "1.0",
                }

                headers = {
                    "x-rapidapi-host": "currency-exchange.p.rapidapi.com",
                    "x-rapidapi-key": "",
                }
                if headers["x-rapidapi-key"] == "":
                    error_window = Toplevel(root)
                    # Geometry of TopLevel
                    error_window.geometry("200x200+370+0")
                    error_window.minsize(200, 100)
                    error_window.maxsize(200, 100)
                    # A Label widget to show in toplevel(Pack)
                    Label(
                        error_window,
                        text="Please Change The API Key\n\n(Line No.67)",
                        font=("Arial", 12, "bold"),
                        fg="Red",
                        padx=30,
                        pady=90,
                    ).pack()
                else:
                    response = requests.request(
                        "GET", url, headers=headers, params=querystring
                    )
                    res = str(response.text)
                    result = float(from_value) * float(res)
                    to_value_var.set(str(result))

        # ======= RESET FUNCTION
        def reset():
            currency_from_var.set("USD")
            currency_to_var.set("INR")
            from_value_var.set("1")
            to_value_var.set("")

        # ======= CLEAR FUNCTION
        def clear():
            from_value_var.set("1")
            to_value_var.set("")

        # ====== BACKGROUND COLOUR : ALL FRAMES
        bg_color = "black"
        # =============================================== TITLE FRAME ==========================================================
        title = Label(
            root,
            text="Currency Converter",
            bd=10,
            relief=GROOVE,
            bg=bg_color,
            fg="white",
            font=("Arial", 18, "bold"),
            pady=2,
        )
        title.pack(fill=X)

        # ================================================= FRAME 1 ============================================================
        F1 = LabelFrame(
            root,
            bd=10,
            relief=GROOVE,
            text="Currency Details",
            bg=bg_color,
            fg="gold",
            font=("Arial", 13, "bold"),
        )
        F1.place(x=0, y=50, relwidth=1)

        # ========== From LABEL
        from_value_lbl = Label(
            F1,
            bg=bg_color,
            fg="white",
            text="From",
            font=("Arial", 13, "bold"),
        )
        from_value_lbl.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

        # ========== VALUE ENTRY BOX
        from_value_entry = Entry(
            F1,
            textvariable=from_value_var,
            width=18,
            font="Courier 13",
            bd=3,
            relief=SUNKEN,
        )
        from_value_entry.grid(row=0, column=1, padx=5, pady=5, sticky="nsew")
        from_value_var.set("1")

        # ========== CURRENCY OPTION MENU (FROM)
        currency_from_options = [
            "AFA",
            "ALL",
            "DZD",
            "AOR",
            "ARS",
            "AMD",
            "AWG",
            "AUD",
            "AZN",
            "BSD",
            "BHD",
            "BDT",
            "BBD",
            "BYN",
            "BZD",
            "BMD",
            "BTN",
            "BOB",
            "BWP",
            "BRL",
            "GBP",
            "BND",
            "BGN",
            "BIF",
            "KHR",
            "CAD",
            "CVE",
            "KYD",
            "XOF",
            "XAF",
            "XPF",
            "CLP",
            "CNY",
            "COP",
            "KMF",
            "CDF",
            "CRC",
            "HRK",
            "CUP",
            "CZK",
            "DKK",
            "DJF",
            "DOP",
            "XCD",
            "EGP",
            "SVC",
            "ERN",
            "EEK",
            "ETB",
            "EUR",
            "FKP",
            "FJD",
            "GMD",
            "GEL",
            "GHS",
            "GIP",
            "XAU",
            "XFO",
            "GTQ",
            "GNF",
            "GYD",
            "HTG",
            "HNL",
            "HKD",
            "HUF",
            "ISK",
            "XDR",
            "INR",
            "IDR",
            "IRR",
            "IQD",
            "ILS",
            "JMD",
            "JPY",
            "JOD",
            "KZT",
            "KES",
            "KWD",
            "LAK",
            "LVL",
            "LBP",
            "LSL",
            "LRD",
            "LYD",
            "LTL",
            "MOP",
            "MKD",
            "MGA",
            "MWK",
            "MYR",
            "MVR",
            "MRO",
            "MUR",
            "MXN",
            "MDL",
            "MNT",
            "MAD",
            "MZN",
            "MMK",
            "NAD",
            "NPR",
            "ANG",
            "NZD",
            "YER",
            "NZD",
            "NIO",
            "KPW",
            "NOK",
            "OMR",
            "PKR",
            "XPD",
            "PAB",
            "PGK",
            "PYG",
            "PEN",
            "PHP",
            "XPT",
            "PLN",
            "QAR",
            "RON",
            "RUB",
            "RWF",
            "SHP",
            "WST",
            "STD",
            "SAR",
            "RSD",
            "SCR",
            "SLL",
            "XAG",
            "SGD",
            "SBD",
            "SOS",
            "ZAR",
            "KRW",
            "LKR",
            "SDG",
            "SRD",
            "SZL",
            "SEK",
            "CHF",
            "SYP",
            "TWD",
            "TJS",
            "TZS",
            "THB",
            "TOP",
            "TTD",
            "TND",
            "TRY",
            "TMT",
            "AED",
            "UGX",
            "XFU",
            "UAH",
            "UYU",
            "USD",
            "UZS",
            "VUN",
            "VEF",
            "VND",
            "YER",
            "ZMK",
            "ZWL",
        ]

        currency_from_optionmenu = OptionMenu(
            F1, currency_from_var, *currency_from_options
        )
        currency_from_optionmenu.grid(row=0, column=2, padx=10, pady=10, sticky="ew")
        currency_from_var.set("USD")

        # ========== TO LABEL
        to_value_lbl = Label(
            F1,
            bg=bg_color,
            fg="white",
            text="To",
            font=("Arial", 13, "bold"),
        )
        to_value_lbl.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")

        # ========== RESULT ENTRY BOX
        to_value_entry = Entry(
            F1,
            textvariable=to_value_var,
            width=18,
            font="Courier 13",
            bd=3,
            fg="white",
            relief=SUNKEN,
            state=DISABLED,
        )
        to_value_entry.grid(row=1, column=1, padx=5, pady=5, sticky="nsew")
        # ========== CURRENCY OPTION MENU (TO)
        currency_to_options = [
            "AFA",
            "ALL",
            "DZD",
            "AOR",
            "ARS",
            "AMD",
            "AWG",
            "AUD",
            "AZN",
            "BSD",
            "BHD",
            "BDT",
            "BBD",
            "BYN",
            "BZD",
            "BMD",
            "BTN",
            "BOB",
            "BWP",
            "BRL",
            "GBP",
            "BND",
            "BGN",
            "BIF",
            "KHR",
            "CAD",
            "CVE",
            "KYD",
            "XOF",
            "XAF",
            "XPF",
            "CLP",
            "CNY",
            "COP",
            "KMF",
            "CDF",
            "CRC",
            "HRK",
            "CUP",
            "CZK",
            "DKK",
            "DJF",
            "DOP",
            "XCD",
            "EGP",
            "SVC",
            "ERN",
            "EEK",
            "ETB",
            "EUR",
            "FKP",
            "FJD",
            "GMD",
            "GEL",
            "GHS",
            "GIP",
            "XAU",
            "XFO",
            "GTQ",
            "GNF",
            "GYD",
            "HTG",
            "HNL",
            "HKD",
            "HUF",
            "ISK",
            "XDR",
            "INR",
            "IDR",
            "IRR",
            "IQD",
            "ILS",
            "JMD",
            "JPY",
            "JOD",
            "KZT",
            "KES",
            "KWD",
            "LAK",
            "LVL",
            "LBP",
            "LSL",
            "LRD",
            "LYD",
            "LTL",
            "MOP",
            "MKD",
            "MGA",
            "MWK",
            "MYR",
            "MVR",
            "MRO",
            "MUR",
            "MXN",
            "MDL",
            "MNT",
            "MAD",
            "MZN",
            "MMK",
            "NAD",
            "NPR",
            "ANG",
            "NZD",
            "YER",
            "NZD",
            "NIO",
            "KPW",
            "NOK",
            "OMR",
            "PKR",
            "XPD",
            "PAB",
            "PGK",
            "PYG",
            "PEN",
            "PHP",
            "XPT",
            "PLN",
            "QAR",
            "RON",
            "RUB",
            "RWF",
            "SHP",
            "WST",
            "STD",
            "SAR",
            "RSD",
            "SCR",
            "SLL",
            "XAG",
            "SGD",
            "SBD",
            "SOS",
            "ZAR",
            "KRW",
            "LKR",
            "SDG",
            "SRD",
            "SZL",
            "SEK",
            "CHF",
            "SYP",
            "TWD",
            "TJS",
            "TZS",
            "THB",
            "TOP",
            "TTD",
            "TND",
            "TRY",
            "TMT",
            "AED",
            "UGX",
            "XFU",
            "UAH",
            "UYU",
            "USD",
            "UZS",
            "VUN",
            "VEF",
            "VND",
            "YER",
            "ZMK",
            "ZWL",
        ]

        currency_to_optionmenu = OptionMenu(F1, currency_to_var, *currency_to_options)
        currency_to_optionmenu.grid(row=1, column=2, padx=10, pady=10, sticky="ew")
        currency_to_var.set("INR")

        # ========== RESET BUTTON
        reset_button = Button(
            F1, text="Reset", command=reset, font=("Arial", 10, "bold")
        )
        reset_button.grid(row=2, column=0, padx=10, pady=5)
        # ========== CLEAR BUTTON
        clear_button = Button(
            F1, text="Clear", command=clear, font=("Arial", 10, "bold")
        )
        clear_button.grid(row=2, column=1, pady=5)
        # ========== SUBMIT BUTTON
        submit_button = Button(
            F1, text="Search", command=submit, font=("Arial", 10, "bold")
        )
        submit_button.grid(row=2, column=2, pady=5)

        root.mainloop()


Window()
