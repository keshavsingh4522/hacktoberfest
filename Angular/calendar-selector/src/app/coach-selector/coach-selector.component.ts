import { Component, OnInit, ChangeDetectionStrategy, NgZone, ChangeDetectorRef, Input, ViewChild, TemplateRef, ViewContainerRef, AfterViewInit, ElementRef } from '@angular/core';
import { NgModel } from '@angular/forms';
import { BehaviorSubject, of } from 'rxjs';
import { concatMap, switchMap } from 'rxjs/operators';
import { Availability } from '../models/availability.model';
import { CoachDateTimeFetchService } from '../services/coach-datetime-fetch.service';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';

@Component({
  selector: 'dummy',
  template: `<p>Well hello there {{abc}}</p>`
})
export class Dummy{
  @Input() abc: string;
}

@Component({
  selector: 'coach-selector',
  changeDetection: ChangeDetectionStrategy.OnPush,
  templateUrl: './coach-selector.component.html',
  styleUrls: ['./coach-selector.component.sass']
})
export class CoachSelectorComponent implements OnInit, AfterViewInit {

  availableCoaches : Array<string> = [];
  testEmitter$ = new BehaviorSubject<Array<string>>(this.availableCoaches);

  @ViewChild(Dummy) test: Dummy;
  @ViewChild('kingkongTemplate') kingKongTemplate: TemplateRef<any>;
  @ViewChild('replacingdiv', { read: ViewContainerRef }) repl: ViewContainerRef;

  constructor(private coachDateTimeFetchService: CoachDateTimeFetchService, private viewContainerRef: ViewContainerRef) {}

  ngAfterViewInit(): void {
    this.repl.createEmbeddedView(this.kingKongTemplate);
  }

  ngOnInit() {
    this.coachDateTimeFetchService.selectedCoaches = new Array();

    // fetches the unique Coach names on app start; meanwhile also getting the availabilities
    this.coachDateTimeFetchService.getCoaches().subscribe(avails => {
      this.availableCoaches = avails;
      for(let ac of this.availableCoaches)
        console.log("COACH AVAILABLE: \n" + ac);
      this.testEmitter$.next(this.availableCoaches);
    }); 


    // this.modal.open(this.kingKongTemplate, { size: 'lg' });
  }

  /**
   * Called when the Coaches are selected
   * @param coach 
   */
  onChange(coach){
    this.coachDateTimeFetchService.selectedCoaches = Array.apply(null, coach)  // convert to real array
      .filter(option => option.selected)
      .map(option => option.value)

      console.log("selected coaches: ", this.coachDateTimeFetchService.selectedCoaches);
  }

  selectDates() {}
}
