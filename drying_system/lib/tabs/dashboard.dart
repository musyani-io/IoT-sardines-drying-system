import 'package:flutter/material.dart';

class DashboardTab extends StatefulWidget {
  const DashboardTab({super.key});

  @override
  State<DashboardTab> createState() => _DashboardTabState();
}

class _DashboardTabState extends State<DashboardTab> {
  // Placeholder data - replace with actual data fetching logic
  String _powerStatus = "ON";
  String _dryingProgress = "34%"; // Initialized to 0%
  String _batteryMode = "DC Mode"; // Default to DC to show new icons
  int _batteryLevel = 75; // Placeholder battery level (0-100)

  String _temperature = "25.0";
  String _humidity = "60";
  String _currentWeight = "1500";

  Widget _getDynamicBatteryIconWidget() {
    if (_batteryMode == "AC Mode") {
      return const Icon(Icons.battery_charging_full, size: 45.0);
    } else {
      // DC Mode
      if (_batteryLevel <= 10) {
        return const Icon(Icons.battery_alert, size: 45.0, color: Colors.red);
      } else if (_batteryLevel <= 20) {
        return const Icon(Icons.battery_1_bar, size: 45.0);
      } else if (_batteryLevel <= 35) {
        return const Icon(Icons.battery_2_bar, size: 45.0);
      } else if (_batteryLevel <= 50) {
        return const Icon(Icons.battery_3_bar, size: 45.0);
      } else if (_batteryLevel <= 65) {
        return const Icon(Icons.battery_4_bar, size: 45.0);
      } else if (_batteryLevel <= 80) {
        return const Icon(Icons.battery_5_bar, size: 45.0);
      } else {
        // Includes > 80 and battery_full equivalent
        return const Icon(Icons.battery_full, size: 45.0);
      }
    }
  }

  Widget _getDynamicDryingProgressIconWidget() {
    try {
      // Remove '%' and parse to int
      final int progress = int.parse(
        _dryingProgress.replaceAll('%', '').trim(),
      );

      if (progress == 0) {
        return const Icon(Icons.hourglass_empty, size: 45.0);
      } else if (progress > 0 && progress < 50) {
        return const Icon(Icons.hourglass_bottom, size: 45.0);
      } else if (progress >= 50 && progress < 100) {
        return const Icon(Icons.hourglass_full, size: 45.0);
      } else if (progress == 100) {
        return const Icon(Icons.check_circle_outline, size: 45.0);
      } else {
        // Fallback for unexpected values (e.g., < 0 or > 100 if data is not clean)
        return const Icon(Icons.hourglass_disabled, size: 45.0);
      }
    } catch (e) {
      // If parsing fails
      return const Icon(Icons.hourglass_disabled, size: 45.0);
    }
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      padding: const EdgeInsets.all(10.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Padding(
            padding: const EdgeInsets.only(left: 8.0, bottom: 8.0, top: 8.0),
            child: Text(
              'System Status',
              style: Theme.of(context).textTheme.headlineSmall,
            ),
          ),
          Card(
            elevation: 4.0,
            child: Column(
              children: [
                ListTile(
                  leading: const Icon(Icons.power_settings_new, size: 45.0),
                  title: Text(
                    'Power',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    _powerStatus,
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
                const Divider(height: 2, indent: 12, endIndent: 12),
                ListTile(
                  leading: _getDynamicDryingProgressIconWidget(),
                  title: Text(
                    'Drying Progress',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    _dryingProgress,
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
                const Divider(height: 2, indent: 12, endIndent: 12),
                ListTile(
                  leading: _getDynamicBatteryIconWidget(),
                  title: Text(
                    'Battery Mode',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    _batteryMode,
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(height: 20.0),
          Padding(
            padding: const EdgeInsets.only(left: 8.0, bottom: 8.0),
            child: Text(
              'Parameters',
              style: Theme.of(context).textTheme.headlineSmall,
            ),
          ),
          Card(
            elevation: 4.0,
            child: Column(
              children: [
                ListTile(
                  leading: const Icon(Icons.thermostat_outlined, size: 45.0),
                  title: Text(
                    'Temperature',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    '$_temperature °C',
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
                const Divider(height: 2, indent: 12, endIndent: 12),
                ListTile(
                  leading: const Icon(Icons.water_drop_outlined, size: 45.0),
                  title: Text(
                    'Humidity',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    '$_humidity %',
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
                const Divider(height: 2, indent: 12, endIndent: 12),
                ListTile(
                  leading: const Icon(Icons.scale_outlined, size: 45.0),
                  title: Text(
                    'Current Weight',
                    style: Theme.of(context).textTheme.titleMedium,
                  ),
                  subtitle: Text(
                    '$_currentWeight g',
                    style: Theme.of(context).textTheme.bodyLarge,
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
