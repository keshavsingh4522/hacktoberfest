# CalendarNshakya

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 11.1.2.

## Features
This is an Angular application. It has the capability to select the desired Coaches and their respective availabilities in order to book a 30-minute time period with them.
- Multi select Coaches to schedule an appointment (Use Ctrl+Click if Windows or CMD+Click if Mac to multi select)
- Select date and time to book an appointment based on weekly view

## How to use
As soon as you get to the home page you are asked to select the Coaches. If you don't select any coach there will be no availability of coaches to display in the calendar view.
After selecting the coaches, click on the `Date Select` to select the date and time to book an appointment. Click on any booking in the calendar to book an appointment. 

## Libraries Used
- `angular` for frontend library
- `bootstrap` for frontend design
- `angular-calendar` for calendar views
- `date-fns` for date manipulation

## Limitations
- Color codes are not added to distinguish between different coaches in the calendar
- Only weekly view is supported as of now

## Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.
## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory. Use the `--prod` flag for a production build.




### Context
Given a CSV dataset that contains the active coaches and their weekly schedule of their available hours, the project helps find the coaches availability and select one that fits the most.
### User Stories That is Applicable using this Framework
- As a User, I want to see which coaches I can schedule with.
- As a User, I want to see what 30 minute timeslots are available to schedule with a particular coach.
- As a User, I want to book an appointment with a coach at one of their available times.
