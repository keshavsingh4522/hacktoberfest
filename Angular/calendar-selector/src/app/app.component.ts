import {
  Component,
  ChangeDetectionStrategy,
  ViewChild,
  TemplateRef,
  OnInit,
} from '@angular/core';
import {
  startOfDay,
  endOfDay,
  subDays,
  addDays,
  endOfMonth,
  isSameDay,
  isSameMonth,
  addHours,
} from 'date-fns';
import { Subject } from 'rxjs';
import { NgbModal, NgbAlert } from '@ng-bootstrap/ng-bootstrap';
import {
  CalendarEvent,
  CalendarEventAction,
  CalendarEventTimesChangedEvent,
  CalendarView,
} from 'angular-calendar';
@Component({
  selector: 'app-root',
  changeDetection: ChangeDetectionStrategy.OnPush,
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.sass']
})
export class AppComponent implements OnInit {

  title = 'calendar-nshakya';

  isInCoachSelectorPage: boolean = true;

  constructor(private modal: NgbModal) {}


  ngOnInit(): void {
  }

  selectCoachChoicePage(): void {
    this.isInCoachSelectorPage = true;
  }

  selectDateChoicePage(): void {
    this.isInCoachSelectorPage = false;
  }
}
