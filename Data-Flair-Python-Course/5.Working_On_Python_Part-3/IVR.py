def menu():
    choice=int(input('Welcome to Star Travels. Thank you for calling us. Please select from the menu\
\n1. Home\n2. Booking\n3. Enquiry\n4. Complaints\n5. Exit'))
    switcher={
        1:'Home',
        2:'Booking',
        3:'Enquiry',
        4:'Complaints',
        5:'Exit'
    }
    return 'Taking you to '+switcher.get(choice,'Please enter a valid choice')
