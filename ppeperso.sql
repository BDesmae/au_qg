-- phpMyAdmin SQL Dump
-- version 4.4.15.5
-- http://www.phpmyadmin.net
--
-- Host: localhost:3306
-- Generation Time: Jun 04, 2018 at 11:57 AM
-- Server version: 5.5.49-log
-- PHP Version: 7.0.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ppeperso`
--

-- --------------------------------------------------------

--
-- Table structure for table `biere`
--

CREATE TABLE IF NOT EXISTS `biere` (
  `id_biere` int(11) NOT NULL,
  `liste_biere` varchar(255) DEFAULT NULL,
  `id_degre` int(11) NOT NULL,
  `id_saveur` int(11) NOT NULL,
  `id_type` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=73 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `biere`
--

INSERT INTO `biere` (`id_biere`, `liste_biere`, `id_degre`, `id_saveur`, `id_type`) VALUES
(1, 'La trop blanche', 1, 1, 1),
(2, 'Brewdog Dead Pony Pale Ale', 1, 1, 2),
(3, 'O''Hara''s Irish Stout', 1, 1, 3),
(4, 'Pas de correspondance, veuillez réessayer', 1, 1, 4),
(5, 'Leffe Ruby', 1, 1, 5),
(6, 'Lindemans Faro', 1, 1, 6),
(7, 'Blanche de Bruxelles', 1, 2, 1),
(8, 'Buxton Special Pale Ale', 1, 2, 2),
(9, 'O''Hara''s Irish Stout', 1, 2, 3),
(10, 'Guinness Draught', 1, 2, 4),
(11, 'Boon Kriek', 1, 2, 5),
(12, 'Kilkenny', 1, 2, 6),
(13, 'Applebocq', 1, 3, 1),
(14, 'Lindemans La Pêcheresse', 1, 3, 2),
(15, 'Pas de correspondance, veuillez réessayer', 1, 3, 3),
(16, 'Plain Porter', 1, 3, 4),
(17, 'Lindemans Kriek', 1, 3, 5),
(18, 'Kilkenny', 1, 3, 6),
(19, 'Blonde du Mont Blanc', 2, 1, 1),
(20, 'Leffe blonde ou Maredsous blonde', 2, 1, 2),
(21, 'Negra Modelo', 2, 1, 3),
(22, 'Founders Porter', 2, 1, 4),
(23, 'Leffe Ruby', 2, 1, 5),
(24, 'Gauloise Ambrée', 2, 1, 6),
(25, 'Blanche des Hornelles', 2, 2, 1),
(26, 'Saison 1858', 2, 2, 2),
(27, 'Leffe Brune', 2, 2, 3),
(28, 'Guinness Extra Stout', 2, 2, 4),
(29, 'Pas de correspondance, veuillez réessayer', 2, 2, 5),
(30, 'Tongerlo Christmas', 2, 2, 6),
(31, 'Paulaner Hefe-Weissbier', 2, 3, 1),
(32, 'Leffe Nectar', 2, 3, 2),
(33, 'Tongerlo Brune ou Duchesse de Bourgogne', 2, 3, 3),
(34, 'Pas de correspondance, veuillez réessayer', 2, 3, 4),
(35, 'Rodenbach Grand Cru', 2, 3, 5),
(36, 'Gauloise Ambrée', 2, 3, 6),
(37, 'Pas de correspondance, veuillez réessayer', 3, 1, 1),
(38, 'Leffe Royale Whitbread Golding', 3, 1, 2),
(39, 'MC Chouffe', 3, 1, 3),
(40, 'Fondus Porter', 3, 1, 4),
(41, 'Leffe Royale Ella', 3, 1, 5),
(42, 'Pêche Mel Bush', 3, 1, 6),
(43, 'La Couagga', 3, 2, 1),
(44, 'Leffe Rituel 9°', 3, 2, 2),
(45, 'Maredsous Brune ou Chimay Bleue', 3, 2, 3),
(46, 'Guinness Foreign Extra Stout', 3, 2, 4),
(47, 'Leffe Royale Mapuche', 3, 2, 5),
(48, 'Ramée Ambrée', 3, 2, 6),
(49, 'La Couagga', 3, 3, 1),
(50, 'Leffe Triple, Leffe Royale Cascade IPA', 3, 3, 2),
(51, 'Leffe Royale Mount Hood', 3, 3, 3),
(52, 'Pas de correspondance, veuillez réessayer', 3, 3, 4),
(53, 'Leffe Royale Mount Hood', 3, 3, 5),
(54, 'Leffe Radieuse', 3, 3, 6),
(55, 'Pas de correspondance, veuillez réessayer', 4, 1, 1),
(56, 'Piraat', 4, 1, 2),
(57, 'Pas de correspondance, veuillez réessayer', 4, 1, 3),
(58, 'Hel & Verdoemeris', 4, 1, 4),
(59, 'Pas de correspondance, veuillez réessayer', 4, 1, 5),
(60, 'Pas de correspondance, veuillez réessayer', 4, 1, 6),
(61, 'Pas de correspondance, veuillez réessayer', 4, 2, 1),
(62, 'Vaudrée Blonde', 4, 2, 2),
(63, 'Abbaye de la Thure', 4, 2, 3),
(64, 'Founders Kentucky', 4, 2, 4),
(65, 'Pas de correspondance, veuillez réessayer', 4, 2, 5),
(66, 'Maredsous Triple', 4, 2, 6),
(67, 'Pas de correspondance, veuillez réessayer', 4, 3, 1),
(68, 'Pas de correspondance, veuillez réessayer', 4, 3, 2),
(69, 'Pas de correspondance, veuillez réessayer', 4, 3, 3),
(70, 'Alex le Rouge', 4, 3, 4),
(71, 'Pas de correspondance, veuillez réessayer', 4, 3, 5),
(72, 'Pas de correspondance, veuillez réessayer', 4, 3, 6);

-- --------------------------------------------------------

--
-- Table structure for table `degre`
--

CREATE TABLE IF NOT EXISTS `degre` (
  `id_degre` int(11) NOT NULL,
  `nom_degre` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `degre`
--

INSERT INTO `degre` (`id_degre`, `nom_degre`) VALUES
(1, 'légère'),
(2, 'moyenne'),
(3, 'forte'),
(4, 'très forte');

-- --------------------------------------------------------

--
-- Table structure for table `saveur`
--

CREATE TABLE IF NOT EXISTS `saveur` (
  `id_saveur` int(11) NOT NULL,
  `nom_saveur` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `saveur`
--

INSERT INTO `saveur` (`id_saveur`, `nom_saveur`) VALUES
(1, 'douce'),
(2, 'amère'),
(3, 'acide');

-- --------------------------------------------------------

--
-- Table structure for table `types`
--

CREATE TABLE IF NOT EXISTS `types` (
  `id_type` int(11) NOT NULL,
  `nom_type` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `types`
--

INSERT INTO `types` (`id_type`, `nom_type`) VALUES
(1, 'blanche'),
(2, 'blonde'),
(3, 'brune'),
(4, 'noire'),
(5, 'rouge'),
(6, 'ambrée');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL,
  `pseudo` varchar(255) NOT NULL,
  `mdp` varchar(255) NOT NULL,
  `mail` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `pseudo`, `mdp`, `mail`) VALUES
(1, 'ben', 'ben', 'ben'),
(2, 'ben', 'ben', 'ben'),
(3, 'Antony', 'azerty', 'antony.cuenot@laposte.net');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `biere`
--
ALTER TABLE `biere`
  ADD PRIMARY KEY (`id_biere`),
  ADD KEY `fk_degre` (`id_degre`),
  ADD KEY `fk_saveur` (`id_saveur`),
  ADD KEY `fk_type` (`id_type`);

--
-- Indexes for table `degre`
--
ALTER TABLE `degre`
  ADD PRIMARY KEY (`id_degre`);

--
-- Indexes for table `saveur`
--
ALTER TABLE `saveur`
  ADD PRIMARY KEY (`id_saveur`);

--
-- Indexes for table `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`id_type`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `biere`
--
ALTER TABLE `biere`
  MODIFY `id_biere` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=73;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `biere`
--
ALTER TABLE `biere`
  ADD CONSTRAINT `fk_degre` FOREIGN KEY (`id_degre`) REFERENCES `degre` (`id_degre`),
  ADD CONSTRAINT `fk_saveur` FOREIGN KEY (`id_saveur`) REFERENCES `saveur` (`id_saveur`),
  ADD CONSTRAINT `fk_type` FOREIGN KEY (`id_type`) REFERENCES `types` (`id_type`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
