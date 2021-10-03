import { TestBed } from '@angular/core/testing';

import { CoachDateTimeFetchService } from './coach-datetime-fetch.service';

describe('Tests CoachDateTimeFetchService', () => {
  let service: CoachDateTimeFetchService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(CoachDateTimeFetchService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
