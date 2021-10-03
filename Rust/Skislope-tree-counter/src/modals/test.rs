#[cfg(test)]
use super::{Map, Vec2};

#[test]
fn test_tuple() {
    let v: Vec2 = (5, 8).into();
    assert_eq!(v.x, 5);
    assert_eq!(v.y, 8);
}

#[test]
fn test_normalize_pos() {
    let m = Map::new((2, 2).into());
    assert_eq!(m.normalize_pos((0, 0).into()), Some((0, 0).into()));
    assert_eq!(m.normalize_pos((1, 0).into()), Some((1, 0).into()));
    assert_eq!(m.normalize_pos((2, 0).into()), Some((0, 0).into()));
    assert_eq!(m.normalize_pos((-1, 0).into()), Some((1, 0).into()));
    assert_eq!(m.normalize_pos((-2, 0).into()), Some((0, 0).into()));
    assert_eq!(m.normalize_pos((0, -1).into()), None);
    assert_eq!(m.normalize_pos((0, 2).into()), None);
}

#[test]
fn test_index() {
    let m = Map::new((3, 5).into());
    assert_eq!(m.index((0, 0).into()), Some(0));
    assert_eq!(m.index((2, 0).into()), Some(2));
    assert_eq!(m.index((0, 1).into()), Some(3));
    assert_eq!(m.index((2, 1).into()), Some(5));
}

#[test]
fn test_generate_itinerary() {
    assert_eq!(
        &Map::generate_itinerary(&Map::new((5, 5).into()), (1, 1).into()),
        &[
            (0, 0).into(),
            (1, 1).into(),
            (2, 2).into(),
            (3, 3).into(),
            (4, 4).into(),
        ],
        "right 1 down 1, 5x5 map"
    );

    assert_eq!(
        &Map::generate_itinerary(&Map::new((5, 5).into()), (3, 1).into()),
        &[
            (0, 0).into(),
            (3, 1).into(),
            (6, 2).into(),
            (9, 3).into(),
            (12, 4).into(),
        ],
        "right 3 down 1, 5x5 map"
    );

    assert_eq!(
        &Map::generate_itinerary(&Map::new((5, 5).into()), (2, 2).into()),
        &[(0, 0).into(), (2, 2).into(), (4, 4).into(),],
        "right 2 down 2, 5x5 map"
    );
    assert_eq!(
        &Map::generate_itinerary(&Map::new((9, 9).into()), (2, 5).into()),
        &[(0, 0).into(), (2, 5).into(),],
        "right 2 down 5, 9x9 map"
    )
}
