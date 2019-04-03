/*--------------               01               ----------------*/
CREATE TABLE ft_table (
	id INT AUTO_INCREMENT NOT NULL, 
	`login` VARCHAR(255) NOT NULL DEFAULT 'toto',
	`group` ENUM('staff', 'student', 'other') NOT NULL,
	`creation_date` DATE NOT NULL,
	PRIMARY KEY (id)
);
