import { NgModule, NgZone } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { CalendarModule, DateAdapter } from 'angular-calendar';
import { adapterFactory } from 'angular-calendar/date-adapters/date-fns';
import { FlatpickrModule } from 'angularx-flatpickr';
import { NgbModalModule, NgbAlertModule } from '@ng-bootstrap/ng-bootstrap';
import { CoachSelectorComponent, Dummy } from './coach-selector/coach-selector.component';
import { DateSelectorComponent } from './date-selector/date-selector.component';
import { CoachDateTimeFetchService } from './services/coach-datetime-fetch.service';
import { HttpClientModule } from '@angular/common/http';
import { NgxCsvParserModule } from 'ngx-csv-parser';
import { CustomifDirective } from './directives/customif.directive';

@NgModule({
  declarations: [
    AppComponent,
    CoachSelectorComponent,
    Dummy,
    DateSelectorComponent,
    CustomifDirective
  ],
  imports: [
    CommonModule,
    FormsModule,
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    NgbModalModule,
    NgbAlertModule,
    NgxCsvParserModule,
    FlatpickrModule.forRoot(),
    CalendarModule.forRoot({ provide: DateAdapter, useFactory: adapterFactory })
  ],
  providers: [
    CoachDateTimeFetchService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
