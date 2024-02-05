// Define a trait for plane figures
trait Figure {
    // Calculate the center of gravity
    fn center_of_gravity(&self) -> (f64, f64);

    // Calculate the perimeter
    fn perimeter(&self) -> f64;

    // Calculate the area
    fn area(&self) -> f64;

    // Scale the figure by a factor
    fn scale(&mut self, factor: f64);

    // Move the figure by a vector
    fn move_by_vector(&mut self, vector: (f64, f64));
}

// Define a struct for Circle
struct Circle {
    center: (f64, f64),
    radius: f64,
}

// Implement the Figure trait for Circle
impl Figure for Circle {
    fn center_of_gravity(&self) -> (f64, f64) {
        self.center
    }

    fn perimeter(&self) -> f64 {
        2.0 * std::f64::consts::PI * self.radius
    }

    fn area(&self) -> f64 {
        std::f64::consts::PI * self.radius * self.radius
    }

    fn scale(&mut self, factor: f64) {
        self.radius *= factor;
    }

    fn move_by_vector(&mut self, vector: (f64, f64)) {
        let (x, y) = self.center;
        self.center = (x + vector.0, y + vector.1);
    }
}

// Define a struct for LineSegment
struct LineSegment {
    start: (f64, f64),
    end: (f64, f64),
}

// Implement the Figure trait for LineSegment
impl Figure for LineSegment {
    fn center_of_gravity(&self) -> (f64, f64) {
        let x = (self.start.0 + self.end.0) / 2.0;
        let y = (self.start.1 + self.end.1) / 2.0;
        (x, y)
    }

    fn perimeter(&self) -> f64 {
        ((self.end.0 - self.start.0).powi(2) + (self.end.1 - self.start.1).powi(2)).sqrt()
    }

    fn area(&self) -> f64 {
        // For simplicity, assuming the area of a line segment is zero
        0.0
    }

    fn scale(&mut self, factor: f64) {
        self.end = (
            self.start.0 + (self.end.0 - self.start.0) * factor,
            self.start.1 + (self.end.1 - self.start.1) * factor,
        );
    }

    fn move_by_vector(&mut self, vector: (f64, f64)) {
        let (dx, dy) = vector;
        self.start = (self.start.0 + dx, self.start.1 + dy);
        self.end = (self.end.0 + dx, self.end.1 + dy);
    }
}

// Define a struct for Triangle
struct Triangle {
    vertex1: (f64, f64),
    vertex2: (f64, f64),
    vertex3: (f64, f64),
}

// Implement the Figure trait for Triangle
impl Figure for Triangle {
    fn center_of_gravity(&self) -> (f64, f64) {
        let x = (self.vertex1.0 + self.vertex2.0 + self.vertex3.0) / 3.0;
        let y = (self.vertex1.1 + self.vertex2.1 + self.vertex3.1) / 3.0;
        (x, y)
    }

    fn perimeter(&self) -> f64 {
        let side1 = ((self.vertex2.0 - self.vertex1.0).powi(2)
            + (self.vertex2.1 - self.vertex1.1).powi(2))
        .sqrt();
        let side2 = ((self.vertex3.0 - self.vertex2.0).powi(2)
            + (self.vertex3.1 - self.vertex2.1).powi(2))
        .sqrt();
        let side3 = ((self.vertex1.0 - self.vertex3.0).powi(2)
            + (self.vertex1.1 - self.vertex3.1).powi(2))
        .sqrt();
        side1 + side2 + side3
    }

    fn area(&self) -> f64 {
        0.5 * ((self.vertex2.0 - self.vertex1.0) * (self.vertex3.1 - self.vertex1.1)
            - (self.vertex3.0 - self.vertex1.0) * (self.vertex2.1 - self.vertex1.1))
            .abs()
    }

    fn scale(&mut self, factor: f64) {
        self.vertex1 = (self.vertex1.0 * factor, self.vertex1.1 * factor);
        self.vertex2 = (self.vertex2.0 * factor, self.vertex2.1 * factor);
        self.vertex3 = (self.vertex3.0 * factor, self.vertex3.1 * factor);
    }

    fn move_by_vector(&mut self, vector: (f64, f64)) {
        let (dx, dy) = vector;
        self.vertex1 = (self.vertex1.0 + dx, self.vertex1.1 + dy);
        self.vertex2 = (self.vertex2.0 + dx, self.vertex2.1 + dy);
        self.vertex3 = (self.vertex3.0 + dx, self.vertex3.1 + dy);
    }
}

// Define a struct for Quadrilateral
struct Quadrilateral {
    vertex1: (f64, f64),
    vertex2: (f64, f64),
    vertex3: (f64, f64),
    vertex4: (f64, f64),
}

// Implement the Figure trait for Quadrilateral
impl Figure for Quadrilateral {
    fn center_of_gravity(&self) -> (f64, f64) {
        let x = (self.vertex1.0 + self.vertex2.0 + self.vertex3.0 + self.vertex4.0) / 4.0;
        let y = (self.vertex1.1 + self.vertex2.1 + self.vertex3.1 + self.vertex4.1) / 4.0;
        (x, y)
    }

    fn perimeter(&self) -> f64 {
        let side1 = ((self.vertex2.0 - self.vertex1.0).powi(2)
            + (self.vertex2.1 - self.vertex1.1).powi(2))
        .sqrt();
        let side2 = ((self.vertex3.0 - self.vertex2.0).powi(2)
            + (self.vertex3.1 - self.vertex2.1).powi(2))
        .sqrt();
        let side3 = ((self.vertex4.0 - self.vertex3.0).powi(2)
            + (self.vertex4.1 - self.vertex3.1).powi(2))
        .sqrt();
        let side4 = ((self.vertex1.0 - self.vertex4.0).powi(2)
            + (self.vertex1.1 - self.vertex4.1).powi(2))
        .sqrt();
        side1 + side2 + side3 + side4
    }

    fn area(&self) -> f64 {
        // For simplicity, assuming the area of a quadrilateral is zero
        0.0
    }

    fn scale(&mut self, factor: f64) {
        self.vertex1 = (self.vertex1.0 * factor, self.vertex1.1 * factor);
        self.vertex2 = (self.vertex2.0 * factor, self.vertex2.1 * factor);
        self.vertex3 = (self.vertex3.0 * factor, self.vertex3.1 * factor);
        self.vertex4 = (self.vertex4.0 * factor, self.vertex4.1 * factor);
    }

    fn move_by_vector(&mut self, vector: (f64, f64)) {
        let (dx, dy) = vector;
        self.vertex1 = (self.vertex1.0 + dx, self.vertex1.1 + dy);
        self.vertex2 = (self.vertex2.0 + dx, self.vertex2.1 + dy);
        self.vertex3 = (self.vertex3.0 + dx, self.vertex3.1 + dy);
        self.vertex4 = (self.vertex4.0 + dx, self.vertex4.1 + dy);
    }
}

// Define a struct for FigureList
struct FigureList {
    figures: Vec<Box<dyn Figure>>,
}

// Implement the Figure trait for FigureList
impl Figure for FigureList {
    fn center_of_gravity(&self) -> (f64, f64) {
        // Calculate the weighted average of the centroids based on area
        let total_area: f64 = self.figures.iter().map(|figure| figure.area()).sum();
        let mut weighted_x_sum = 0.0;
        let mut weighted_y_sum = 0.0;

        for figure in &self.figures {
            let area_fraction = figure.area() / total_area;
            let (x, y) = figure.center_of_gravity();
            weighted_x_sum += area_fraction * x;
            weighted_y_sum += area_fraction * y;
        }

        (weighted_x_sum, weighted_y_sum)
    }

    fn perimeter(&self) -> f64 {
        // Sum of perimeters of all figures in the list
        self.figures.iter().map(|figure| figure.perimeter()).sum()
    }

    fn area(&self) -> f64 {
        // Sum of areas of all figures in the list
        self.figures.iter().map(|figure| figure.area()).sum()
    }

    fn scale(&mut self, factor: f64) {
        // Scale all figures in the list
        for figure in &mut self.figures {
            figure.scale(factor);
        }
    }

    fn move_by_vector(&mut self, vector: (f64, f64)) {
        // Move all figures in the list
        for figure in &mut self.figures {
            figure.move_by_vector(vector);
        }
    }
}

// Implement the main function for testing
fn main() {
    // Create a figure that is a list of figures containing a circle, a triangle, and a quadrilateral
    let mut figure_list = FigureList {
        figures: vec![
            Box::new(Circle {
                center: (0.0, 0.0),
                radius: 2.0,
            }),
            Box::new(Triangle {
                vertex1: (0.0, 0.0),
                vertex2: (3.0, 0.0),
                vertex3: (1.5, 4.0),
            }),
            Box::new(Quadrilateral {
                vertex1: (0.0, 0.0),
                vertex2: (2.0, 0.0),
                vertex3: (2.0, 2.0),
                vertex4: (0.0, 2.0),
            }),
        ],
    };

    // Shift the figure by the vector (1, 1)
    figure_list.move_by_vector((1.0, 1.0));

    // Scale by a factor of 2
    figure_list.scale(2.0);

    // Print the perimeter, area, and centroid coordinates of the figure
    println!("Perimeter: {}", figure_list.perimeter());
    println!("Area: {}", figure_list.area());
    println!("Centroid: {:?}", figure_list.center_of_gravity());
}