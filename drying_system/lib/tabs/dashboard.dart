import 'package:flutter/material.dart';

class DashboardTab extends StatefulWidget {
  const DashboardTab({super.key});

  @override
  State<DashboardTab> createState() => _DashboardTabState();
}

class _DashboardTabState extends State<DashboardTab> {
  // Placeholder values - you'll replace these with actual data later
  final double _temperature = 25.5;
  final int _humidity = 60;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.all(10.0),
        child: Card(
          elevation: 3.5, // Add some shadow to the card
          child: Column(
            mainAxisSize: MainAxisSize.min, // To make the card wrap its content
            children: <Widget>[
              ListTile(
                leading: const Icon(
                  Icons.thermostat,
                  size: 45.0,
                ), // Icon for temperature
                title: const Text(
                  'Temperature',
                  style: TextStyle(fontWeight: FontWeight.w600),
                ),
                subtitle: Text(
                  '$_temperature °C',
                  style: TextStyle(
                    fontSize: 18.0,
                    color: Theme.of(context).colorScheme.secondary,
                  ),
                ),
              ),
              const Divider(
                height: 3,
                indent: 12,
                endIndent: 12,
              ), // Visual separator
              ListTile(
                leading: const Icon(
                  Icons.opacity,
                  size: 45.0,
                ), // Icon for humidity
                title: const Text(
                  'Humidity',
                  style: TextStyle(fontWeight: FontWeight.w600),
                ),
                subtitle: Text(
                  '$_humidity%',
                  style: TextStyle(
                    fontSize: 18.0,
                    color: Theme.of(context).colorScheme.secondary,
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
