mod modals;
use modals::{Map, Tile, Vec2};

fn main() {
    let map = Map::parse(include_bytes!("input.txt"));

    println!("{:?}", map);

    // from the problem statement
    let deltas: &[Vec2] = &[
        (1, 1).into(),
        (3, 1).into(),
        (5, 1).into(),
        (7, 1).into(),
        (1, 2).into(),
    ];

    let hit = deltas
        .iter()
        .copied()
        // generate all itineraries
        .map(|delta| Map::generate_itinerary(&map, delta))
        // count trees
        .map(|itin| {
            itin.into_iter()
                .filter(|&pos| map.get(pos) == Tile::Tree)
                .count()
        })
        // multiply everything together
        .product::<usize>();

    println!("The multiproduct of all trees hit is {}", hit);
}
