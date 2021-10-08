#has_high_income = False
has_criminal_record = True
has_good_credit = True
#and: both condition
#or: at least on
#NOT : convert to opp
if has_good_credit and not has_criminal_record:
    print("eligible for loan ")
else:
    print("Not eligible for loan")